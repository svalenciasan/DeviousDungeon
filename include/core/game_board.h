#pragma once

#include "cinder/gl/gl.h"
#include "vector"
#include "map"
#include "tile.h"
#include "player.h"

using std::vector;
using std::map;
using deviousdungeon::player::Player;
using deviousdungeon::tile::Tile;

namespace deviousdungeon {
namespace gameboard {
class GameBoard {
 public:
  //Creates a board with those dimensions.
  GameBoard(const size_t rows, const size_t columns);
  //Returns player location
  vec2 Move();
 private:
  //Probability of each tile being chosen during board generation.
  map<tile::TileType, double> probability_of_tile_;
  size_t current_level_;
  Player player_;
  vec2 player_location_;
  vector<vector<Tile>> board_;

  //Generates a random board
  vector<vector<Tile>> GenerateRandomBoard();
};
}//namespace deviousdungeon
}//namespace player