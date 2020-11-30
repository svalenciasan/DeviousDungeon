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
  Weapon(WeaponType weapon_type, int power);

  int SetPower(int other_power);
  int GetPower() const;
  WeaponType GetType() const;
 private:
  int power_ = 0;
  WeaponType weapon_type_;
};
}//namespace weapon
}//namespace deviousdungeon