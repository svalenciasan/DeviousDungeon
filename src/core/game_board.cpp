#include <random>
#include "core/game_board.h"
#include "core/player.h"
#include "core/tile.h"
#include "core/enemy_tile.h"
#include "core/weapon_tile.h"
#include "core/gold_tile.h"
#include "core/health_tile.h"
#include "core/portal_tile.h"

using std::rand;
using deviousdungeon::player::Player;
using deviousdungeon::tile::Tile;
using deviousdungeon::tile::PortalTile;


using deviousdungeon::gameboard::GameBoard;

namespace deviousdungeon {

namespace gameboard {
GameBoard::GameBoard(const vec2& dimensions) {
  probability_of_tile_[tile::kEnemy_Tile] = 10;
  probability_of_tile_[tile::kWeapon_Tile] = 8;
  probability_of_tile_[tile::kGold_Tile] = 3;
  probability_of_tile_[tile::kHealth_Tile] = 5;

  board_.resize(static_cast<size_t>(dimensions.y));
  for (size_t row = 0; row < dimensions.y; row++) {
    board_.at(row).resize(static_cast<size_t>(dimensions.x));
  }
  GenerateRandomBoard();
}
vector<vector<Tile>> GameBoard::GenerateRandomBoard() {
//  //Randomizing the exit portal;
//  PortalTile portal_tile;
//  size_t portal_spawn = rand()%board_[0].size();
//  board_[0][portal_spawn] = portal_tile;
  //Splitting map into tiles and weight vectors
  vector<tile::TileType> tiles;
  vector<double> weights;
  for (auto it = probability_of_tile_.begin(); it != probability_of_tile_.end(); ++it) {
    tiles.push_back(it->first);
    weights.push_back(it->second);
  }
  //Creating the discrete distribution. Weighted probability.
  std::discrete_distribution<int> dist(begin(weights), end(weights));
  std::mt19937 gen;
  gen.seed(static_cast<size_t>(time(0)));

  size_t number_of_squares = board_.size() * board_.at(0).size();
  std::vector<int> samples(number_of_squares);
  for(auto& i: samples) {
    i = dist(gen);
  }
//
//  for (size_t row = 0; row < height; row++) {
//    for (size_t column = 0; column < height; column++) {
//      probability_of_tile_;
//    }
//  }
return board_;
}
}//namespace gameboard

}//namespace deviousdungeon