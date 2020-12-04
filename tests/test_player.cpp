#include <catch2/catch.hpp>
#include <core/player.h>
#include <core/weapon.h>

using deviousdungeon::player::Player;
using deviousdungeon::weapon::Weapon;
using deviousdungeon::weapon::WeaponType;

TEST_CASE("Heal Player", "[heal]") {
  Player player;
  Enemy enemy(2);
SECTION("Healing to full health") {
  assert(player.GetMaxHealth() == 3);
  assert(player.GetHealth() == 3);
  player.UseMelee(enemy);
  assert(player.GetMaxHealth() == 3);
  assert(player.GetHealth() == 1);
  player.Heal(2);
  assert(player.GetMaxHealth() == 3);
  assert(player.GetHealth() == 3);
}
SECTION("Healing past full health") {
    assert(player.GetMaxHealth() == 3);
    assert(player.GetHealth() == 3);
    player.UseMelee(enemy);
    assert(player.GetMaxHealth() == 3);
    assert(player.GetHealth() == 1);
    player.Heal(5);
    assert(player.GetMaxHealth() == 3);
    assert(player.GetHealth() == 3);
}
}
TEST_CASE("Pickup Weapon", "[weapon]") {
  Player player;
  SECTION("No Weapons") {
    assert(player.GetWeapon(deviousdungeon::weapon::kMeleeWeapon).GetPower() == 0);
    assert(player.GetWeapon(deviousdungeon::weapon::kRangedWeapon).GetPower() == 0);
  }
  SECTION("Picking up weapons with no weapons in inventory") {
    Weapon melee_weapon(deviousdungeon::weapon::kMeleeWeapon,5);
    Weapon ranged_weapon(deviousdungeon::weapon::kRangedWeapon,5);

    player.EquipWeapon(melee_weapon);
    player.EquipWeapon(ranged_weapon);

    assert(player.GetWeapon(deviousdungeon::weapon::kMeleeWeapon).GetPower() == 5);
    assert(player.GetWeapon(deviousdungeon::weapon::kRangedWeapon).GetPower() == 5);
  }
  SECTION("Picking up weapons with weaker weapons in inventory") {
    Weapon melee_weapon(deviousdungeon::weapon::kMeleeWeapon,5);
    Weapon ranged_weapon(deviousdungeon::weapon::kRangedWeapon,5);

    player.EquipWeapon(melee_weapon);
    player.EquipWeapon(ranged_weapon);

    Weapon melee_weapon2(deviousdungeon::weapon::kMeleeWeapon,6);
    Weapon ranged_weapon2(deviousdungeon::weapon::kRangedWeapon,6);

    player.EquipWeapon(melee_weapon2);
    player.EquipWeapon(ranged_weapon2);

    assert(player.GetWeapon(deviousdungeon::weapon::kMeleeWeapon).GetPower() == 6);
    assert(player.GetWeapon(deviousdungeon::weapon::kRangedWeapon).GetPower() == 6);
  }
  SECTION("Picking up weapons with stronger weapons in inventory") {
    Weapon melee_weapon(deviousdungeon::weapon::kMeleeWeapon,5);
    Weapon ranged_weapon(deviousdungeon::weapon::kRangedWeapon,5);

    player.EquipWeapon(melee_weapon);
    player.EquipWeapon(ranged_weapon);

    Weapon melee_weapon2(deviousdungeon::weapon::kMeleeWeapon,2);
    Weapon ranged_weapon2(deviousdungeon::weapon::kRangedWeapon,2);

    player.EquipWeapon(melee_weapon2);
    player.EquipWeapon(ranged_weapon2);

    assert(player.GetWeapon(deviousdungeon::weapon::kMeleeWeapon).GetPower() == 2);
    assert(player.GetWeapon(deviousdungeon::weapon::kRangedWeapon).GetPower() == 2);
  }
}