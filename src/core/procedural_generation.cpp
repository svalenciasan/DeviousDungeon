#include <random>
#include "core/procedural_generation.h"

using std::rand;
using deviousdungeon::proceduralgeneration::ProceduralGeneration;

namespace deviousdungeon {

namespace proceduralgeneration {
ProceduralGeneration::ProceduralGeneration() {
  //Tile probability
  probability_of_tile_[tile::kEnemy_Tile] = 10;
  probability_of_tile_[tile::kWeapon_Tile] = 7;
  probability_of_tile_[tile::kGold_Tile] = 4;
  probability_of_tile_[tile::kHealth_Tile] = 3;
  //Enemy power probability
  enemy_power_probability_[1] = 10;
  enemy_power_probability_[2] = 8;
  enemy_power_probability_[3] = 6;
  enemy_power_probability_[4] = 4;
  enemy_power_probability_[5] = 2;
  enemy_power_probability_[6] = 1;
  enemy_power_probability_[7] = 0.5;
  //Weapon type probability
  weapon_type_probability_[weapon::kMeleeWeapon] = 10;
  weapon_type_probability_[weapon::kRangedWeapon] = 5;
  //Melee weapon power probability
  melee_weapon_power_probability_[1] = 10;
  melee_weapon_power_probability_[2] = 7;
  melee_weapon_power_probability_[3] = 5;
  melee_weapon_power_probability_[4] = 3;
  //Ranged weapon power probability
  ranged_weapon_power_probability_[3] = 10;
  ranged_weapon_power_probability_[4] = 7;
  ranged_weapon_power_probability_[5] = 5;
  ranged_weapon_power_probability_[6] = 3;
}
/**
 * Public functions
 */
vector<vector<Tile*>> ProceduralGeneration::GenerateRandomBoard(size_t rows, size_t columns) {
  vector<vector<Tile*>> board(rows, vector<Tile*>(columns));
  //Random seed for current generation
  size_t seed = static_cast<size_t>(time(0));
  seeds_.push_back(seed);
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

  for (size_t row = 0; row < board.size(); row++) {
    for (size_t column = 0; column < board[row].size(); column++) {
      if (board[row][column] != NULL &&
          (board[row][column]->GetTileType() == tile::kSpawnTile || board[row][column]->GetTileType() == tile::kPortalTile)) {
        continue;
      }
      switch (tiles.at(dist(gen))) {
        case tile::kEnemy_Tile: {
          EnemyTile *enemy_tile = new EnemyTile(GenerateRandomEnemy());
          board[row][column] = enemy_tile;
          break;
        }
        case tile::kWeapon_Tile: {
          WeaponTile *weapon_tile = new WeaponTile(GenerateRandomWeapon());
          board[row][column] = weapon_tile;
          break;
        }
        case tile::kGold_Tile: {
          GoldTile *gold_tile = new GoldTile();
          board[row][column] = gold_tile;
          break;
        }
        case tile::kHealth_Tile: {
          HealthTile *health_tile = new HealthTile();
          board[row][column] = health_tile;
          break;
        }
      }
    }
  }
  return board;
}
Enemy ProceduralGeneration::GenerateRandomEnemy() {
  //Splitting map into tiles and weight vectors
  vector<size_t> power;
  vector<double> weights;
  for (auto it = enemy_power_probability_.begin(); it != enemy_power_probability_.end(); ++it) {
    power.push_back(it->first);
    weights.push_back(it->second);
  }
  //Creating the discrete distribution. Weighted probability.
  std::discrete_distribution<int> dist(begin(weights), end(weights));
  std::mt19937 gen;
  gen.seed(seeds_.back());
  return Enemy(power.at(dist(gen)));
}
Weapon ProceduralGeneration::GenerateRandomWeapon() {
  weapon::WeaponType type = GenerateRandomWeaponType();
  return Weapon(type, GenerateRandomWeaponPower(type));
}
/**
 * Getters/Setters
 */
size_t ProceduralGeneration::AddSeed(size_t seed) {
  seeds_.push_back(seed);
}

vector<size_t> ProceduralGeneration::GetSeeds() const {
  return seeds_;
}
//Private
/**
 * Procedural Generation
 */
size_t ProceduralGeneration::GenerateRandomPortal(vector<vector<Tile*>>& board) {
  //Randomizing the exit portal at top row
  size_t portal_location = rand() % board[0].size();
  PortalTile* portal_tile = new PortalTile();
  board[0][portal_location] = portal_tile;
  return portal_location;
}

size_t ProceduralGeneration::GenerateRandomSpawn(vector<vector<Tile*>>& board) {
  srand(rand());
  //Randomizing the spawn point at last row
  size_t spawn_location = rand() % board[board.size() - 1].size();
  SpawnTile* spawn_tile = new SpawnTile();
  board[board.size() - 1][spawn_location] = spawn_tile;
  srand(seeds_.back());
  return spawn_location;
}

weapon::WeaponType ProceduralGeneration::GenerateRandomWeaponType() {
  vector<weapon::WeaponType> weapon_type;
  vector<double> weapon_type_weights;
  for (auto it = weapon_type_probability_.begin(); it != weapon_type_probability_.end(); ++it) {
    weapon_type.push_back(it->first);
    weapon_type_weights.push_back(it->second);
  }
  //Creating the discrete distribution. Weighted probability.
  std::discrete_distribution<int> dist(begin(weapon_type_weights), end(weapon_type_weights));
  std::mt19937 gen;
  gen.seed(seeds_.back());

  return weapon_type.at(dist(gen));
}

size_t ProceduralGeneration::GenerateRandomWeaponPower(weapon::WeaponType type) {
  vector<size_t> power;
  vector<double> weights;
  switch (type) {
    case weapon::kMeleeWeapon: {
      for (auto it = melee_weapon_power_probability_.begin(); it != melee_weapon_power_probability_.end(); ++it) {
        power.push_back(it->first);
        weights.push_back(it->second);
      }
      break;
    }
    case weapon::kRangedWeapon: {
      for (auto it = ranged_weapon_power_probability_.begin(); it != ranged_weapon_power_probability_.end(); ++it) {
        power.push_back(it->first);
        weights.push_back(it->second);
      }
      break;
    }
  }
  //Creating the discrete distribution. Weighted probability.
  std::discrete_distribution<int> dist(begin(weights), end(weights));
  std::mt19937 gen;
  gen.seed(seeds_.back());

  return power.at(dist(gen));
}

}//namespace proceduralgeneration

}//namespace deviousdungeon
