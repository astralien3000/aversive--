#include <device/eirbot2014/ax12.hpp>

void send_set_message(Ax12& c, char* msg) {
	std::ostringstream oss;
	oss << "SET " << msg;
	ClientThread::instance().
		sendDeviceMessage(c, 
				oss.str().c_str());
	return;
}

void Ax12::parseAndAct(char* msg){
	QStringList list=QString(msg).split(" ");
	QStringListIterator it=list.begin();
	if(it++->compare("VALUE")==0)
		return;
	else {
		if(*it=="SPEED")
			data.speed=(*(++it)).toInt();
		else if(*it=="TORQUE")
			data.speed=(*(++it)).toInt();
		else
			data.position=(*it).toInt();
	}	
	return;
}


Ax12::Ax12(char* name):IODevice(name){
	data={0,0,0,JOIN,POSITION};
	ClientThread::instance().
		registerDevice(*this,std::function<void(char*)>(
					[this](char* msg) mutable -> void {
						this->parseAndAct(msg);
					}));

}

Ax12::~Ax12(){}


u16 Ax12::getAngle() const{
	if(data.wM==WHEEL)
		return 0;
	else {
		setMode("position");
		return getValue();
	 }
}

u16 Ax12::getSpeed() const{
	setMode("speed");
	return getValue();
}

u16 Ax12::getTorque() const{
	setMode("torque");
	return getValue();
}

u16 Ax12::getValue() const {
	switch(data.sM){
		case POSITION:
			return data.angle;
		case SPEED:
			return data.speed;
		case TORQUE;
			return data.torque;
		default:
			return 0;
	}
}

void Ax12::setValue() const {
	std::ostringstream oss;
	oss << (SPEED==data.sM)?"VALUE SPEED":"VALUE " << val;

	ClientThread::instance().
		sendDeviceMessage(*this, 
				oss.str().c_str());
	return;
}

void Ax12::setAngle(u16 val){
	if(data.wM==WHEEL)
		return;
	else {
		setMode("position");
		setValue(val);
	}
	return;
}

void Ax12::setSpeed(u16 val){
		setMode("speed");
		setValue(val);
		setMode("position");
	return;
}

void Ax12::setMode(char* mode){
	QString bob(mode);
	if(bob=="position") {
		data.sM=POSITION;
	}

	if(bob=="speed") {
		data.sM=SPEED;
	}

	if(bob=="torque") {
		data.sM=TORQUE;
	}

	if(bob=="wheel") {
		data.wM=WHEEL;
		send_set_message(*this, "WHEEL");
	}
	
	if(bob=="join") {
		data.wM=JOIN;
		send_set_message(*this, "JOIN");
	}
	return;
}

void setAngleMax(u16 min, u16 max) {
	std::ostringstream oss;
	oss << "SET MAX ANGLE " << min << " " << max;
	send_set_message(*this,oss.str().c_str());
}

void setTorqueMax(u16 max) {
	std::ostringstream oss;
	oss << "MAX TORQUE " << max;
	send_set_message(*this,oss.str().c_str());
}


