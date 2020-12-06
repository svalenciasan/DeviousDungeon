#include "core/player.h"

//using deviousdungeon::player::Player;

namespace deviousdungeon {
namespace player {
int Player::AddCoins(int coins) {
  coins_ += coins;
  return coins_;
}

int Player::Heal(int heal) {
  current_health_ += heal;
  if (current_health_ > max_health_) {
    current_health_ = max_health_;
  }
  return current_health_;
}

int Player::UseMelee(Enemy& enemy) {
  int power_difference = enemy.GetPower() - melee_weapon_.GetPower();
  if (power_difference >= 0) {
    current_health_ -= power_difference;
    enemy.SetPower(0);
    melee_weapon_.SetPower(0);
    return 0;
  } else {
    melee_weapon_.SetPower(abs(power_difference));
    enemy.SetPower(0);
    return melee_weapon_.GetPower();
  }
}

int Player::UseRanged(Enemy& enemy) {
  int power_difference = enemy.GetPower() - ranged_weapon_.GetPower();
  if (power_difference >= 0) {
    enemy.SetPower(power_difference);
    ranged_weapon_.SetPower(0);
    return ranged_weapon_.GetPower();
  } else {
    ranged_weapon_.SetPower(abs(power_difference));
    enemy.SetPower(0);
    return ranged_weapon_.GetPower();
  }
}

void Player::EquipWeapon(Weapon& weapon) {
  switch (weapon.GetType()) {
    case weapon::kMeleeWeapon:
      melee_weapon_ = weapon;
      break;
    case weapon::kRangedWeapon:
      ranged_weapon_ = weapon;
      break;
  }
}

/**
 * Getters/Setters
 */
 int Player::GetHealth() const {
   return current_health_;
 }

 int Player::SetHealth(int health) {
   current_health_ = health;
   return current_health_;
 }

 int Player::GetMaxHealth() const {
   return max_health_;
 }

 Weapon Player::GetWeapon(weapon::WeaponType weapon_type) {
   switch (weapon_type) {
     case weapon::kMeleeWeapon:
       return melee_weapon_;
     default:
       return ranged_weapon_;
   }
 }

 int Player::GetCoins() const{
   return coins_;
 }
}//namespace player
}//namespace deviousdungeon