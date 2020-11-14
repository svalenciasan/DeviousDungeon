#pragma once

#include "cinder/gl/gl.h"
#include "weapon.h"

using deviousdungeon::weapon::Weapon;

namespace deviousdungeon {
namespace player {
class Player {
 public:
  Player() = default;
  size_t Fight(size_t power);
  size_t Shoot(size_t power);
  size_t TakeCoins(size_t coins);
  size_t Heal(size_t heal);
 private:
  size_t health_ = 3;
  size_t coins_ = 0;
  Weapon melee_weapon;
  Weapon ranged_weapon;
//  Weapon melee_weapon = Weapon(weapon::kMeleeWeapon, 0);
//  Weapon ranged_weapon = Weapon(weapon::kRangedWeapon, 0);
};
}//namespace deviousdungeon
}//namespace player