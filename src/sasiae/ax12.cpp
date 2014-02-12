#include <device/eirbot2014/ax12.hpp>

void send_set_message(Ax12& c, const char* msg) {
	std::ostringstream oss;
	oss << "SET " << msg;
	ClientThread::instance().
		sendDeviceMessage(c, 
				oss.str().c_str());
	return;
}

Ax12::Ax12(char* name):Device(name){
	data={0,0,0,JOIN,POSITION};
	ClientThread::instance().
		registerDevice(*this,std::function<void(char*)>(
					[this](char* msg) mutable -> void {
					QStringList list=QString(msg).split(" ");
					QStringList::const_iterator it=list.constBegin();
					if(!(*it++=="VALUE"))
					return;
					else {
						if(*it=="SPEED")
							data.speed=(*(++it)).toInt();
						else if(*it=="TORQUE")
							data.speed=(*(++it)).toInt();
						else
							data.angle=(*it).toInt();
					}
					}));

}

Ax12::~Ax12(){}

u16 Ax12::getValue() const {
	switch(data.sM){
		case POSITION:
			return data.angle;
		case SPEED:
			return data.speed;
		case TORQUE:
			return data.torque;
		default:
			return 0;
	}
}

void Ax12::setValue(u16 val) {
	std::ostringstream oss;
	oss << (SPEED==data.sM)?"VALUE SPEED ":"VALUE ";
 	oss	<< val;

	ClientThread::instance().
		sendDeviceMessage(*this, 
				oss.str().c_str());
	return;
}

void Ax12::setMode(const char* bob){
	QString mode = bob;
	if(mode=="position") {
		data.sM=POSITION;
	}

	if(mode=="speed") {
		data.sM=SPEED;
	}

	if(mode=="torque") {
		data.sM=TORQUE;
	}

	if(mode=="wheel") {
		data.wM=WHEEL;
		send_set_message(*this, "WHEEL");
	}
	
	if(mode=="join") {
		data.wM=JOIN;
		send_set_message(*this, "JOIN");
	}
	return;
}

u16 Ax12::getAngle() {
	if(data.wM==WHEEL)
		return 0;
	else {
		setMode("position");
		return getValue();
	 }
}

u16 Ax12::getSpeed() {
	setMode("speed");
	return getValue();
}

u16 Ax12::getTorque() {
	setMode("torque");
	return getValue();
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

void Ax12::setAngleMax(u16 min, u16 max) {
	std::ostringstream oss;
	oss << "SET MAX ANGLE " << min << " " << max;
	send_set_message(*this,oss.str().c_str());
}

void Ax12::setTorqueMax(u16 max) {
	std::ostringstream oss;
	oss << "MAX TORQUE " << max;
	send_set_message(*this,oss.str().c_str());
}


