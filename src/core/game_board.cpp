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
using deviousdungeon::tile::EnemyTile;
using deviousdungeon::tile::HealthTile;
using deviousdungeon::tile::WeaponTile;
using deviousdungeon::tile::GoldTile;


using deviousdungeon::gameboard::GameBoard;

namespace deviousdungeon {

namespace gameboard {
GameBoard::GameBoard(const size_t rows, const size_t columns) {
  probability_of_tile_[tile::kEnemy_Tile] = 10;
  probability_of_tile_[tile::kWeapon_Tile] = 7;
  probability_of_tile_[tile::kGold_Tile] = 4;
  probability_of_tile_[tile::kHealth_Tile] = 3;

  board_.resize(static_cast<size_t>(rows));
  for (size_t row = 0; row < rows; row++) {
    board_.at(row).resize(static_cast<size_t>(columns));
  }
  GenerateRandomBoard();
}
vector<vector<Tile>> GameBoard::GenerateRandomBoard() {
  //Randomizing the exit portal;
  PortalTile portal_tile;
  size_t portal_spawn = rand()%board_[0].size();
  //board_[0][portal_spawn] = portal_tile;
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

  for (size_t row = 0; row < board_.size(); row++) {
    for (size_t column = 0; column < board_[row].size(); column++) {
      if(row == 0 && column == portal_spawn) {
        continue;
      }
//      switch (dist(gen)) {
//        case tile::kEnemy_Tile:
//          board_[row][column] = EnemyTile();
//          break;
//
//        case tile::kWeapon_Tile:
//          board_[row][column] = WeaponTile();
//          break;
//
//        case tile::kGold_Tile:
//          board_[row][column] = GoldTile();
//          break;
//
//        case tile::kHealth_Tile:
//          board_[row][column] = HealthTile();
//          break;
//      }
    }
  }
return board_;
}
}//namespace gameboard

}//namespace deviousdungeon