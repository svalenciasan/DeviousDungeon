#include <random>
#include "core/game_board.h"

using std::rand;
using deviousdungeon::gameboard::GameBoard;

namespace deviousdungeon {

namespace gameboard {
GameBoard::GameBoard(const size_t rows, const size_t columns) : kRows(rows), kColumns(columns) {
  board_ = procedural_generation_.GenerateRandomBoard(rows, columns);
  for (size_t column = 0; column < columns; column++) {
    if (board_[board_.size() - 1][column]->GetTileType() == tile::kSpawnTile) {
      player_location_ = vec2(column, board_.size() - 1);
      break;
    }
  }
}

vec2 GameBoard::Move(Direction direction) {
  size_t lower_bound = board_.size() - 1;
  size_t right_bound = board_[lower_bound].size() - 1;

  switch (direction) {
    case kUp:
      if (player_location_.y == 0) {
        return player_location_;
      }
      MakeEmptyTile(player_location_);
      player_location_ -= vec2(0,1);
      OnEnter(player_location_);
      break;

    case kDown:
      if (player_location_.y == lower_bound) {
        return player_location_;
      }
      MakeEmptyTile(player_location_);
      player_location_ += vec2(0,1);
      OnEnter(player_location_);
      break;

    case kLeft:
      if (player_location_.x == 0) {
        return player_location_;
      }
      MakeEmptyTile(player_location_);
      player_location_ -= vec2(1,0);
      OnEnter(player_location_);
      break;

    case kRight:
      if (player_location_.x == right_bound) {
        return player_location_;
      }
      MakeEmptyTile(player_location_);
      player_location_ += vec2(1,0);
      OnEnter(player_location_);
      break;
  }
  return player_location_;
}

/**
 * Getters/Setters
 */
 vector<vector<Tile *>> GameBoard::GetBoard() const {
   return board_;
 }

 GameState GameBoard::GetGameState() const {
   return state_;
 }

 size_t GameBoard::GetColumns() const {
   return kColumns;
 }

size_t GameBoard::GetRows() const {
   return kRows;
}

size_t GameBoard::GetLevel() const {
   return current_level_;
}

vec2 GameBoard::GetPlayerLocation() const {
  return player_location_;
}

Player GameBoard::GetPlayer() const {
  return player_;
}

/**
 * Private/Helper
 */

 vec2 GameBoard::MakeEmptyTile(vec2 location) {
   delete board_[static_cast<size_t>(location.y)][static_cast<size_t>(location.x)];
   EmptyTile* empty_tile = new EmptyTile();
   board_[static_cast<size_t>(location.y)][static_cast<size_t>(location.x)] = empty_tile;
   return location;
 }

 void GameBoard::GenerateNextLevel() {
   //Update probabilities
   procedural_generation_.UpdateProbabilities(current_level_);
   //Generate board
   board_ = procedural_generation_.GenerateRandomBoard(kRows, kColumns);
   //Set player spawn point
   for (size_t column = 0; column < kColumns; column++) {
     if (board_[board_.size() - 1][column]->GetTileType() == tile::kSpawnTile) {
       player_location_ = vec2(column, board_.size() - 1);
       break;
     }
   }
 }

 void GameBoard::OnEnter(vec2 location) {
  switch (board_[static_cast<size_t>(location.y)][static_cast<size_t>(location.x)]->GetTileType()) {
    case tile::kEnemy_Tile: {
      EnemyTile* enemy_tile = static_cast<EnemyTile*>(board_[static_cast<size_t>(location.y)][static_cast<size_t>(location.x)]);
      enemy_tile->OnEnter(player_);
      if (player_.GetHealth() <= 0) {
        state_ = kGameOver;
      }
      break;
    }
    case tile::kWeapon_Tile: {
      WeaponTile* weapon_tile = static_cast<WeaponTile*>(board_[static_cast<size_t>(location.y)][static_cast<size_t>(location.x)]);
      weapon_tile->OnEnter(player_);
      break;
    }
    case tile::kHealth_Tile: {
      HealthTile* health_tile = static_cast<HealthTile*>(board_[static_cast<size_t>(location.y)][static_cast<size_t>(location.x)]);
      health_tile->OnEnter(player_);
      break;
    }
    case tile::kGold_Tile: {
      GoldTile* gold_tile = static_cast<GoldTile*>(board_[static_cast<size_t>(location.y)][static_cast<size_t>(location.x)]);
      gold_tile->OnEnter(player_);
      break;
    }
    case tile::kPortalTile: {
      current_level_++;
      GenerateNextLevel();
      //Used to avoid making an empty tile at the portal location
      return;
    }
    case tile::kEmpty_Tile: {
      state_ = kGameOver;
      break;
    }
  }
  MakeEmptyTile(location);
 }
}//namespace gameboard

}//namespace deviousdungeon