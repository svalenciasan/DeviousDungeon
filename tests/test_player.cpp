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
TEST_CASE("Pickup Coins", "[coins]") {
  Player player;
  SECTION("No Coins") {
    assert(player.GetCoins() == 0);
    player.AddCoins(50);
    assert(player.GetCoins() == 50);
  }
  SECTION("Already have coins") {
    assert(player.GetCoins() == 0);
    player.AddCoins(50);
    assert(player.GetCoins() == 50);
    player.AddCoins(50);
    assert(player.GetCoins() == 100);
  }
}

TEST_CASE("Use melee", "[melee]") {
  Player player;
  SECTION("More damage than health") {
    Enemy enemy(4);
    player.UseMelee(enemy);

    assert(enemy.GetPower() == 0);
    assert(player.GetHealth() == 0);
  }
  SECTION("Same damage as health") {
    Enemy enemy(3);
    player.UseMelee(enemy);

    assert(enemy.GetPower() == 0);
    assert(player.GetHealth() == 0);
  }
  SECTION("Weapon with same damage as enemy") {
    Enemy enemy(3);
    Weapon weapon(deviousdungeon::weapon::kMeleeWeapon, 3);
    player.EquipWeapon(weapon);
    player.UseMelee(enemy);

    assert(player.GetWeapon(deviousdungeon::weapon::kMeleeWeapon).GetPower() == 0);
    assert(enemy.GetPower() == 0);
    assert(player.GetHealth() == 3);
  }
  SECTION("Weapon with less damage as enemy") {
    Enemy enemy(3);
    Weapon weapon(deviousdungeon::weapon::kMeleeWeapon, 2);
    player.EquipWeapon(weapon);
    player.UseMelee(enemy);

    assert(player.GetWeapon(deviousdungeon::weapon::kMeleeWeapon).GetPower() == 0);
    assert(enemy.GetPower() == 0);
    assert(player.GetHealth() == 2);
  }
  SECTION("Weapon with more damage as enemy") {
    Enemy enemy(3);
    Weapon weapon(deviousdungeon::weapon::kMeleeWeapon, 4);
    player.EquipWeapon(weapon);
    player.UseMelee(enemy);

    assert(player.GetWeapon(deviousdungeon::weapon::kMeleeWeapon).GetPower() == 1);
    assert(enemy.GetPower() == 0);
    assert(player.GetHealth() == 3);
  }
}

TEST_CASE("Use ranged", "[ranged]") {
  Player player;
  SECTION("No ranged weapon") {
    Enemy enemy(4);
    player.UseRanged(enemy);

    assert(enemy.GetPower() == 4);
    assert(player.GetHealth() == 3);
  }
  SECTION("Weapon with same damage as enemy") {
    Enemy enemy(3);
    Weapon weapon(deviousdungeon::weapon::kRangedWeapon, 3);
    player.EquipWeapon(weapon);
    player.UseRanged(enemy);

    assert(player.GetWeapon(deviousdungeon::weapon::kRangedWeapon).GetPower() == 0);
    assert(enemy.GetPower() == 0);
    assert(player.GetHealth() == 3);
  }
  SECTION("Weapon with less damage as enemy") {
    Enemy enemy(3);
    Weapon weapon(deviousdungeon::weapon::kRangedWeapon, 2);
    player.EquipWeapon(weapon);
    player.UseRanged(enemy);

    assert(player.GetWeapon(deviousdungeon::weapon::kRangedWeapon).GetPower() == 0);
    assert(enemy.GetPower() == 1);
    assert(player.GetHealth() == 3);
  }
  SECTION("Weapon with more damage as enemy") {
    Enemy enemy(3);
    Weapon weapon(deviousdungeon::weapon::kRangedWeapon, 4);
    player.EquipWeapon(weapon);
    player.UseRanged(enemy);

    assert(player.GetWeapon(deviousdungeon::weapon::kRangedWeapon).GetPower() == 1);
    assert(enemy.GetPower() == 0);
    assert(player.GetHealth() == 3);
  }
}