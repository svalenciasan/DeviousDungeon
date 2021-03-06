#pragma once

#include "cinder/gl/gl.h"
#include "weapon.h"
#include "enemy.h"
#include "cinder/audio/audio.h"
#include "cinder/app/RendererGl.h"
#include "cinder/app/App.h"

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
  int GetCoins() const;
  int Heal(int heal);
  int GetHealth()const;
  int GetMaxHealth()const;
  int SetHealth(int health);
  Weapon GetWeapon(weapon::WeaponType weapon_type);
 private:
  int max_health_ = 3;
  int current_health_ = 3;
  int coins_ = 0;
  Weapon melee_weapon_;
  Weapon ranged_weapon_;
};
}//namespace player
}//namespace deviousdungeon