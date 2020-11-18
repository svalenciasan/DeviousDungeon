#include <random>
#include "core/game_board.h"

using std::rand;
using deviousdungeon::gameboard::GameBoard;

namespace deviousdungeon {

namespace gameboard {
GameBoard::GameBoard(const size_t rows, const size_t columns) {
  board_ = procedural_generation_.GenerateRandomBoard(rows, columns);
  for (size_t column = 0; column < columns; column++) {
    if (board_[board_.size() - 1][column]->GetTileType() == tile::kSpawnTile) {
      player_location_ = vec2(column, board_.size() - 1);
    }
  }
}

vec2 GameBoard::Move(Direction direction) {
  size_t lower_bound = board_.size() - 1;
  size_t right_bound = board_[lower_bound].size() - 1;

  switch (direction) {
    case kUp:
      if (player_location_.y == 0) {
        break;
      }
      MakeEmptyTile(player_location_);
      player_location_ -= vec2(0,1);
      break;

    case kDown:
      if (player_location_.y == lower_bound) {
        break;
      }
      MakeEmptyTile(player_location_);
      player_location_ += vec2(0,1);
      break;

    case kLeft:
      if (player_location_.x == 0) {
        break;
      }
      MakeEmptyTile(player_location_);
      player_location_ -= vec2(1,0);
      break;

    case kRight:
      if (player_location_.x == right_bound) {
        break;
      }
      MakeEmptyTile(player_location_);
      player_location_ += vec2(1,0);
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

 vec2 GameBoard::GetPlayerLocation() const {
   return player_location_;
 }
 //Private
 vec2 GameBoard::MakeEmptyTile(vec2 location) {
   delete board_[static_cast<size_t>(location.y)][static_cast<size_t>(location.x)];
   EmptyTile* empty_tile = new EmptyTile();
   board_[static_cast<size_t>(location.y)][static_cast<size_t>(location.x)] = empty_tile;
   return location;
 }

}//namespace gameboard

}//namespace deviousdungeon