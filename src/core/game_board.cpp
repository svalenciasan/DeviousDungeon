#include <random>
#include "core/game_board.h"

using std::rand;
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

/**
 * Getters/Setters
 */
 vector<vector<Tile *>> GameBoard::GetBoard() const {
   return board_;
 }

 vec2 GameBoard::GetPlayerLocation() const {
   return player_location_;
 }
/**
 * Procedural Generation
 */
 size_t GameBoard::GenerateRandomPortal() {
  //Randomizing the exit portal at top row
  size_t portal_location = rand() % board_[0].size();
  PortalTile* portal_tile = new PortalTile();
  board_[0][portal_location] = portal_tile;
  return portal_location;
 }

 size_t GameBoard::GenerateRandomSpawn() {
  //Randomizing the spawn point at last row
  size_t spawn_location = rand() % board_[board_.size() - 1].size();
  SpawnTile* spawn_tile = new SpawnTile();
  board_[board_.size() - 1][spawn_location] = spawn_tile;
  player_location_ = vec2(board_.size() - 1, spawn_location);
  return spawn_location;
 }
 vector<vector<Tile*>> GameBoard::GenerateRandomBoard() {
   //Random seed for current generation
   size_t seed = static_cast<size_t>(time(0));
   seeds_.push_back(seed);
   srand(seed);
   //Setting the portal and spawn locations
   size_t portal_location = GenerateRandomPortal();
   //Used this to randomize the spawn location to not be the same as the portal.
   srand(rand());
   size_t spawn_location = GenerateRandomSpawn();
   srand(seed);
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
   gen.seed(seed);

   for (size_t row = 0; row < board_.size(); row++) {
     for (size_t column = 0; column < board_[row].size(); column++) {
       if (row == 0 && column == portal_location || row == board_.size() - 1 && column == spawn_location) {
         continue;
       }
       switch (tiles.at(dist(gen))) {
         case tile::kEnemy_Tile: {
           EnemyTile *enemy_tile = new EnemyTile();
           board_[row][column] = enemy_tile;
           break;
         }
         case tile::kWeapon_Tile: {
           WeaponTile *weapon_tile = new WeaponTile();
           board_[row][column] = weapon_tile;
           break;
         }
         case tile::kGold_Tile: {
           GoldTile *gold_tile = new GoldTile();
           board_[row][column] = gold_tile;
           break;
         }
         case tile::kHealth_Tile: {
           HealthTile *health_tile = new HealthTile();
           board_[row][column] = health_tile;
           break;
         }
       }
     }
   }
   return board_;
 }

}//namespace gameboard

}//namespace deviousdungeon