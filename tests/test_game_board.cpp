#include <catch2/catch.hpp>
#include <core/game_board.h>

using deviousdungeon::gameboard::GameBoard;

TEST_CASE("Constructor", "[constructor]") {
  SECTION("Constructor") {
    GameBoard game_board(5, 5);
    assert(game_board.GetGameState() == deviousdungeon::gameboard::kInProgress);
    assert(game_board.GetLevel() == 1);
    assert(game_board.GetScore() == 0);
    assert(game_board.GetRows() == 5);
    assert(game_board.GetColumns() == 5);
    assert(game_board.GetPlayer().GetHealth() == 3);
  }
}
TEST_CASE("Movement", "[move]") {
  EnemyTile* enemy_tile = new EnemyTile(Enemy(4));
  Weapon weapon(deviousdungeon::weapon::kMeleeWeapon, 2);
  WeaponTile* weapon_tile = new WeaponTile(weapon);
  PortalTile* portal_tile = new PortalTile();
  GoldTile* gold_tile = new GoldTile(4);
  HealthTile* health_tile = new HealthTile(2);
  SpawnTile* spawn_tile = new SpawnTile();

  vector<vector<Tile*>> board{{portal_tile, gold_tile, health_tile},
                              {spawn_tile, weapon_tile, enemy_tile}};

  GameBoard game_board(board);
  assert(game_board.GetPlayerLocation() == vec2(0,1));
  SECTION("Movement right with space") {
    game_board.Move(deviousdungeon::gameboard::kRight);

    assert(game_board.GetPlayerLocation() == vec2(1,1));
  }
  SECTION("Movement up with space") {
    game_board.Move(deviousdungeon::gameboard::kRight);
    assert(game_board.GetPlayerLocation() == vec2(1,1));

    game_board.Move(deviousdungeon::gameboard::kUp);
    assert(game_board.GetPlayerLocation() == vec2(1,0));
  }
  SECTION("Movement left with space") {
    game_board.Move(deviousdungeon::gameboard::kRight);
    assert(game_board.GetPlayerLocation() == vec2(1,1));
    game_board.Move(deviousdungeon::gameboard::kRight);
    assert(game_board.GetPlayerLocation() == vec2(2,1));
    game_board.Move(deviousdungeon::gameboard::kUp);
    assert(game_board.GetPlayerLocation() == vec2(2,0));

    game_board.Move(deviousdungeon::gameboard::kLeft);
    assert(game_board.GetPlayerLocation() == vec2(1,0));
  }
  SECTION("Movement down with space") {
    game_board.Move(deviousdungeon::gameboard::kRight);
    assert(game_board.GetPlayerLocation() == vec2(1,1));

    game_board.Move(deviousdungeon::gameboard::kUp);
    assert(game_board.GetPlayerLocation() == vec2(1,0));

    game_board.Move(deviousdungeon::gameboard::kRight);
    assert(game_board.GetPlayerLocation() == vec2(2,0));

    game_board.Move(deviousdungeon::gameboard::kDown);
    assert(game_board.GetPlayerLocation() == vec2(2,1));
  }

  SECTION("Move left when no space") {
    game_board.Move(deviousdungeon::gameboard::kLeft);

    assert(game_board.GetPlayerLocation() == vec2(0,1));
  }
  SECTION("Move down no space") {
    game_board.Move(deviousdungeon::gameboard::kDown);

    assert(game_board.GetPlayerLocation() == vec2(0,1));
  }
  SECTION("Move right no space") {
    game_board.Move(deviousdungeon::gameboard::kRight);
    game_board.Move(deviousdungeon::gameboard::kRight);

    assert(game_board.GetPlayerLocation() == vec2(2,1));
    game_board.Move(deviousdungeon::gameboard::kRight);

    assert(game_board.GetPlayerLocation() == vec2(2,1));
  }
  SECTION("Move up no space") {
    game_board.Move(deviousdungeon::gameboard::kRight);
    game_board.Move(deviousdungeon::gameboard::kUp);
    assert(game_board.GetPlayerLocation() == vec2(1,0));

    game_board.Move(deviousdungeon::gameboard::kUp);
    assert(game_board.GetPlayerLocation() == vec2(1,0));
  }
}

TEST_CASE("Moving in tiles", "[tiles]") {
  EnemyTile* enemy_tile = new EnemyTile(Enemy(4));
  Weapon weapon(deviousdungeon::weapon::kMeleeWeapon, 2);
  WeaponTile* weapon_tile = new WeaponTile(weapon);
  PortalTile* portal_tile = new PortalTile();
  GoldTile* gold_tile = new GoldTile(4);
  HealthTile* health_tile = new HealthTile(2);
  SpawnTile* spawn_tile = new SpawnTile();

  vector<vector<Tile*>> board{{portal_tile, health_tile, enemy_tile},
                              {spawn_tile, weapon_tile, gold_tile}};

  GameBoard game_board(board);
  assert(game_board.GetPlayerLocation() == vec2(0,1));
  SECTION("Movement into weapon tile") {
    assert(game_board.GetPlayer().GetWeapon(deviousdungeon::weapon::kMeleeWeapon).GetPower() == 0);

    game_board.Move(deviousdungeon::gameboard::kRight);

    assert(game_board.GetPlayer().GetWeapon(deviousdungeon::weapon::kMeleeWeapon).GetPower() == 2);
  }
  SECTION("Movement into gold tile") {
    game_board.Move(deviousdungeon::gameboard::kRight);
    game_board.Move(deviousdungeon::gameboard::kRight);

    assert(game_board.GetPlayer().GetCoins() == 4);
  }
  SECTION("Movement into enemy tile") {
    game_board.Move(deviousdungeon::gameboard::kRight);
    assert(game_board.GetPlayer().GetWeapon(deviousdungeon::weapon::kMeleeWeapon).GetPower() == 2);
    game_board.Move(deviousdungeon::gameboard::kRight);
    assert(game_board.GetPlayer().GetHealth() == 3);


    game_board.Move(deviousdungeon::gameboard::kUp);
    assert(game_board.GetPlayer().GetHealth() == 1);
    game_board.Move(deviousdungeon::gameboard::kRight);
    assert(game_board.GetPlayer().GetWeapon(deviousdungeon::weapon::kMeleeWeapon).GetPower() == 0);
  }
  SECTION("Movement into health tile") {
    game_board.Move(deviousdungeon::gameboard::kRight);
    assert(game_board.GetPlayer().GetWeapon(deviousdungeon::weapon::kMeleeWeapon).GetPower() == 2);
    game_board.Move(deviousdungeon::gameboard::kRight);
    assert(game_board.GetPlayer().GetHealth() == 3);
    game_board.Move(deviousdungeon::gameboard::kUp);
    assert(game_board.GetPlayer().GetHealth() == 1);
    game_board.Move(deviousdungeon::gameboard::kRight);
    assert(game_board.GetPlayer().GetWeapon(deviousdungeon::weapon::kMeleeWeapon).GetPower() == 0);

    game_board.Move(deviousdungeon::gameboard::kLeft);
    assert(game_board.GetPlayer().GetHealth() == 3);
  }
  SECTION("Movement into empty tile") {
    game_board.Move(deviousdungeon::gameboard::kRight);
    game_board.Move(deviousdungeon::gameboard::kLeft);

    assert(game_board.GetPlayer().GetHealth() == 0);

    game_board.Move(deviousdungeon::gameboard::kRight);
    assert(game_board.GetPlayerLocation() == vec2(0,1));
  }
}