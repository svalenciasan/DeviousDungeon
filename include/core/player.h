#pragma once

#include "cinder/gl/gl.h"
#include "weapon.h"
#include "enemy.h"

using deviousdungeon::weapon::Weapon;
using deviousdungeon::enemy::Enemy;

namespace deviousdungeon {
namespace player {
class Player {
 public:
  Player() = default;
  /**
   *
   * @param enemy
   * @return The melee weapon's remaining power value
   */
  int UseMelee(Enemy& enemy);
  /**
   *
   * @param enemy
   * @return The ranged weapon's remaining power value
   */
  int UseRanged(Enemy& enemy);
  void EquipWeapon(Weapon& weapon);
  int AddCoins(int coins);
  int Heal(int heal);
 private:
  int max_health_ = 3;
  int current_health_ = 3;
  int coins_ = 0;
  Weapon melee_weapon;
  Weapon ranged_weapon;
};
}//namespace player
}//namespace deviousdungeon