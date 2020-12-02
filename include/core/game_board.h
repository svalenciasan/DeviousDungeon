#pragma once

#include "cinder/gl/gl.h"
#include "vector"
#include "map"
#include "memory"
#include "core/tiles/tile.h"
#include "core/procedural_generation.h"
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
using deviousdungeon::proceduralgeneration::ProceduralGeneration;
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
enum GameState {
  kInProgress,
  kGameOver,
  kWinGame,
};
class GameBoard {
 public:
  GameBoard() = default;
  //Creates a board with those dimensions.
  GameBoard(const size_t rows, const size_t columns);
  /**
   * Changes player location.
   * @param direction
   * @return
   */
  vec2 Move(Direction direction);

  /**
   * Getters/Setters.
   */
  vector<vector<Tile*>> GetBoard() const;
  GameState GetGameState() const;
  size_t GetRows() const;
  size_t GetColumns() const;
  size_t GetLevel() const;
  vec2 GetPlayerLocation() const;
  Player GetPlayer() const;

 private:
  size_t kRows = 0;
  size_t kColumns = 0;
  GameState state_ = kInProgress;
  //Note:(0,0) is the top-left corner unless stated otherwise.
  ProceduralGeneration procedural_generation_;
  size_t current_level_ = 1;
  Player player_;
  //X component corresponds to the column while y component corresponds to the row.
  vec2 player_location_;
  vector<vector<Tile*>> board_;
  /**
   * Turns a tile into an kEmptyTile.
   * @param location
   * @return
   */
  vec2 MakeEmptyTile(vec2 location);
  void OnEnter(vec2 location);
  void GenerateNextLevel();
};
}//namespace gameboard
}//namespace deviousdungeon