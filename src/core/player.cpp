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
  int power_difference = enemy.GetPower() - melee_weapon.GetPower();
  if (power_difference >= 0) {
    current_health_ -= power_difference;
    enemy.SetPower(0);
    melee_weapon.SetPower(0);
    return 0;
  } else {
    melee_weapon.SetPower(abs(power_difference));
    enemy.SetPower(0);
    return melee_weapon.GetPower();
  }
}

int Player::UseRanged(Enemy& enemy) {
  int power_difference = enemy.GetPower() - ranged_weapon.GetPower();
  if (power_difference >= 0) {
    enemy.SetPower(power_difference);
    return ranged_weapon.GetPower();
  } else {
    ranged_weapon.SetPower(abs(power_difference));
    enemy.SetPower(0);
    return ranged_weapon.GetPower();
  }
}

void Player::EquipWeapon(Weapon& weapon) {
  switch (weapon.GetType()) {
    case weapon::kMeleeWeapon:
      melee_weapon = weapon;
      break;
    case weapon::kRangedWeapon:
      ranged_weapon = weapon;
      break;
  }
}
}//namespace player
}//namespace deviousdungeon