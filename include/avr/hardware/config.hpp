#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "../../common/base/integer.hpp"

template<int SIZE, typename C1, typename C2> class ConfigInter;
template<int SIZE, typename C1, typename C2> class ConfigUnion;
template<int SIZE, typename C1> class ConfigNeg;

template<int SIZE, typename C1, typename C2>
class ConfigOp {
protected:
  const C1* const _c1;
  const C2* const _c2;
public:
  inline ConfigOp(const C1* c1, const C2* c2) : _c1(c1), _c2(c2) {}

  template<typename OtherConfig>
  inline const ConfigInter<SIZE, ConfigOp<SIZE, C1, C2>, OtherConfig> operator&(const OtherConfig& other) const {
    return ConfigInter<SIZE, ConfigOp<SIZE, C1, C2>, OtherConfig>(this, &other);
  }

  template<typename OtherConfig>
  inline const ConfigUnion<SIZE, ConfigOp<SIZE, C1, C2>, OtherConfig> operator|(const OtherConfig& other) const {
    return ConfigUnion<SIZE, ConfigOp<SIZE, C1, C2>, OtherConfig>(this, &other);
  }

  inline const ConfigNeg<SIZE, ConfigOp<SIZE, C1, C2> > operator~(void) const {
    return ConfigNeg<SIZE, ConfigOp<SIZE, C1, C2> >(this);
  }

  inline typename Integer<SIZE>::Unsigned value(int i) const;
};

template<int SIZE, typename C1, typename C2>
class ConfigInter : public ConfigOp<SIZE, C1, C2> {
public:
  inline ConfigInter(const C1* c1, const C2* c2) : ConfigOp<SIZE, C1, C2>::ConfigOp(c1, c2) {}

  inline typename Integer<SIZE>::Unsigned value(int i) const {
    return this->_c1->value(i) & this->_c2->value(i);
  }
};

template<int SIZE, typename C1, typename C2>
class ConfigUnion : public ConfigOp<SIZE, C1, C2> {
public:
  inline ConfigUnion(const C1* c1, const C2* c2) : ConfigOp<SIZE, C1, C2>::ConfigOp(c1, c2) {}

  inline typename Integer<SIZE>::Unsigned value(int i) const {
    return this->_c1->value(i) | this->_c2->value(i);
  }
};

template<int SIZE, typename C1>
class ConfigNeg : public ConfigOp<SIZE, C1, C1> {
public:
  inline ConfigNeg(const C1* c1) : ConfigOp<SIZE, C1, C1>::ConfigOp(c1, 0) {}

  inline typename Integer<SIZE>::Unsigned value(int i) const {
    return ~this->_c1->value(i);
  }
};

template<int SIZE, int ID>
class Config {
protected:
  typename Integer<SIZE>::Unsigned const conf[3];
public:
  inline Config(void);

  template<typename OtherConfig>
  inline const ConfigInter<SIZE, Config<SIZE, ID>, OtherConfig> operator&(const OtherConfig& other) const {
    return ConfigInter<SIZE, Config<SIZE, ID>, OtherConfig>(this, &other);
  }

  template<typename OtherConfig>
  inline const ConfigUnion<SIZE, Config<SIZE, ID>, OtherConfig> operator|(const OtherConfig& other) const {
    return ConfigUnion<SIZE, Config<SIZE, ID>, OtherConfig>(this, &other);
  }

  inline const ConfigNeg<SIZE, Config<SIZE, ID> > operator~(void) const {
    return ConfigNeg<SIZE, Config<SIZE, ID> >(this);
  }

  inline typename Integer<SIZE>::Unsigned value(int i) const {
    return conf[i];
  }
};

template<int SIZE>
class ConfigVal {
protected:
  typename Integer<SIZE>::Unsigned const val;
public:
  inline ConfigVal(typename Integer<SIZE>::Unsigned v) : val(v) {}

  template<typename OtherConfig>
  inline const ConfigInter<SIZE, ConfigVal<SIZE>, OtherConfig> operator&(const OtherConfig& other) const {
    return ConfigInter<SIZE, ConfigVal<SIZE>, OtherConfig>(this, &other);
  }

  template<typename OtherConfig>
  inline const ConfigUnion<SIZE, ConfigVal<SIZE>, OtherConfig> operator|(const OtherConfig& other) const {
    return ConfigUnion<SIZE, ConfigVal<SIZE>, OtherConfig>(this, &other);
  }

  inline const ConfigNeg<SIZE, ConfigVal<SIZE> > operator~(void) const {
    return ConfigNeg<SIZE, ConfigVal<SIZE> >(this);
  }

  inline typename Integer<SIZE>::Unsigned value(int i) const {
    return val >> (i * SIZE);
  }
};


#define CFG(c) Config<c::SIZE,c::CONFIG>()
#define VAL(r, v) ConfigVal<r::SIZE>(v)

#endif//CONFIG_HPP
