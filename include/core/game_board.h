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
namespace gameboard {
enum Direction {
  kUp,
  kDown,
  kLeft,
  kRight
};
class GameBoard {
 public:
  GameBoard() = default;
  //Creates a board with those dimensions.
  GameBoard(const size_t rows, const size_t columns);
  //Changes player location
  vec2 Move(Direction direction);

  /**
   * Getters/Setters.
   */
  vector<vector<Tile*>> GetBoard() const;
  vec2 GetPlayerLocation() const;
 private:
  //Note:(0,0) is the top-left corner unless stated otherwise.
  //Probability of each tile being chosen during board generation.
  map<tile::TileType, double> probability_of_tile_;
  size_t current_level_;
  Player player_;
  //The x component corresponds to the column, the y component is the row.
  vec2 player_location_;
  vector<vector<Tile*>> board_;
  /**
   * List of all seeds for every level.
   */
  vector<size_t> seeds_;
  vec2 MakeEmptyTile(vec2 location);
  /**
   * Adds random portal location to board.
   * @return Portal column location.
   */
  size_t GenerateRandomPortal();
  /**
   * Adds random spawn location to board.
   * @return Spawn column location.
   */
  size_t GenerateRandomSpawn();
  vector<vector<Tile*>> GenerateRandomBoard();
};
}//namespace gameboard
}//namespace deviousdungeon