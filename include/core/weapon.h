#pragma once

#include "cinder/gl/gl.h"

namespace deviousdungeon {
namespace weapon {
enum WeaponType {
  kMeleeWeapon,
  kRangedWeapon
};
class Weapon {
 public:
  //Random power
  Weapon() = default;
  Weapon(WeaponType weapon_type);
  Weapon(WeaponType weapon_type, size_t power);
  size_t UseWeapon(size_t other_power);
  size_t GetPower();
 private:
  size_t power_;
  WeaponType weapon_type_;
};
}//namespace weapon
}//namespace deviousdungeon