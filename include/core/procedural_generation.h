#pragma once

#include "cinder/gl/gl.h"
#include "vector"
#include "map"
#include "memory"
#include "core/tiles/tile.h"
#include "core/tiles/enemy_tile.h"
#include "core/tiles/weapon_tile.h"
#include "core/tiles/gold_tile.h"
#include "core/tiles/health_tile.h"
#include "core/tiles/portal_tile.h"
#include "core/tiles/empty_tile.h"
#include "core/tiles/spawn_tile.h"
#include "player.h"

using std::vector;
using std::unique_ptr;
using std::map;
using deviousdungeon::tile::Tile;
using deviousdungeon::tile::PortalTile;
using deviousdungeon::tile::SpawnTile;
using deviousdungeon::tile::EnemyTile;
using deviousdungeon::tile::HealthTile;
using deviousdungeon::tile::WeaponTile;
using deviousdungeon::tile::GoldTile;
using deviousdungeon::tile::EmptyTile;
using deviousdungeon::player::Player;

namespace deviousdungeon {
namespace proceduralgeneration {
class ProceduralGeneration {
 public:
  ProceduralGeneration();
  //ProceduralGeneration(size_t rows, size_t columns);

  vector<vector<Tile*>> GenerateRandomBoard(size_t rows, size_t columns);
  Enemy GenerateRandomEnemy();
  Weapon GenerateRandomWeapon();
  /**
   * Getters/Setters.
   */
  vector<size_t> GetSeeds() const;
  size_t AddSeed(size_t seed);
 private:
  //Probability of each tile being chosen during board generation.
  map<tile::TileType, double> probability_of_tile_;
  //Damage of enemy to probability
  map<size_t, double> enemy_power_probability_;
  //Probability of each weapon type appearing.
  map<weapon::WeaponType, double> weapon_type_probability_;
  map<size_t, double> melee_weapon_power_probability_;
  map<size_t, double> ranged_weapon_power_probability_;
  /**
   * List of all seeds for every level.
   */
  vector<size_t> seeds_;
  //Private helper
  /**
   * Adds random portal location to board.
   * @return Portal column location.
   */
  size_t GenerateRandomPortal(vector<vector<Tile*>>& board);
  /**
   * Adds random spawn location to board.
   * @return Spawn column location.
   */
  size_t GenerateRandomSpawn(vector<vector<Tile*>>& board);
  size_t GenerateRandomWeaponPower(weapon::WeaponType type);
  weapon::WeaponType GenerateRandomWeaponType();
};
}//namespace procedural_generation
}//namespace deviousdungeon