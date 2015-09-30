#ifndef MEMORY_MAPPING_HPP
#define MEMORY_MAPPING_HPP

#include "integer.hpp"

namespace MemoryMapping {

  template<typename RegType, typename Group> struct Register;
  template<typename RegType, typename Group, int BITNUM> struct BitField;
  template<typename RegType, typename Group, RegType MASK> struct Field;
  template<typename RegType, typename Group, RegType MASK> struct Config;

  template<typename Register, typename Next> struct VirtualField;
  template<typename Register, typename Next> struct VirtualConfig;

  // Aliases
  //// Register
  template<typename Group> using Register8  = Register<u8 , Group>;
  template<typename Group> using Register16 = Register<u16, Group>;
  template<typename Group> using Register32 = Register<u32, Group>;
  template<typename Group> using Register64 = Register<u64, Group>;

  //// Config
  template<typename Group, u8  MASK> using Config8  = Config<u8 , Group, MASK>;
  template<typename Group, u16 MASK> using Config16 = Config<u16, Group, MASK>;
  template<typename Group, u32 MASK> using Config32 = Config<u32, Group, MASK>;
  template<typename Group, u64 MASK> using Config64 = Config<u64, Group, MASK>;

  //// Field
  template<typename Group, u8  MASK> using Field8  = Field<u8 , Group, MASK>;
  template<typename Group, u16 MASK> using Field16 = Field<u16, Group, MASK>;
  template<typename Group, u32 MASK> using Field32 = Field<u32, Group, MASK>;
  template<typename Group, u64 MASK> using Field64 = Field<u64, Group, MASK>;

  //// BitField
  template<typename Group, int BITNUM> using BitField8  = BitField<u8 , Group, BITNUM>;
  template<typename Group, int BITNUM> using BitField16 = BitField<u16, Group, BITNUM>;
  template<typename Group, int BITNUM> using BitField32 = BitField<u32, Group, BITNUM>;
  template<typename Group, int BITNUM> using BitField64 = BitField<u64, Group, BITNUM>;


  // Private functions
  namespace Private {
    template<typename RegType>
    inline constexpr RegType  field_value(const RegType mask, const RegType value, const RegType res = 0, const int offset = 0) {
      return (mask)?field_value(mask>>1, (mask&1)?value>>1:value, res | ((value & mask & 1)<<offset), offset+1):res;
    }
  }

}

#include "register.hpp"
#include "config.hpp"
#include "field.hpp"
#include "bitfield.hpp"

#include "register_impl.hpp"
#include "config_impl.hpp"
#include "field_impl.hpp"
#include "bitfield_impl.hpp"

#endif//MEMORY_MAPPING_HPP
