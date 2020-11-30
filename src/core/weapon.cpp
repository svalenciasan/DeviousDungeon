#include "core/player.h"

//using deviousdungeon::player::Player;

namespace deviousdungeon {
namespace weapon {
Weapon::Weapon(WeaponType weapon_type) {
  weapon_type_ = weapon_type;
  power_ = rand() % 1 + 7;
}
Weapon::Weapon(WeaponType weapon_type, int power) {
  weapon_type_ = weapon_type;
  power_ = power;
}

int Weapon::SetPower(int other_power) {
  return 5;
}

int Weapon::GetPower() const{
  return power_;
}

WeaponType Weapon::GetType() const{
  return weapon_type_;
}
}//namespace weapon
}//namespace deviousdungeon