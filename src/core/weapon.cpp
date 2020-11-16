#include "core/player.h"

//using deviousdungeon::player::Player;

namespace deviousdungeon {
namespace weapon {
Weapon::Weapon(WeaponType weapon_type) {
  weapon_type_ = weapon_type;
  power_ = rand() % 1 + 7;
}
Weapon::Weapon(WeaponType weapon_type, size_t power) {
  weapon_type_ = weapon_type;
  power_ = power;
}
size_t Weapon::UseWeapon(size_t other_power) {
  return power_ - other_power;
}
}//namespace weapon
}//namespace deviousdungeon