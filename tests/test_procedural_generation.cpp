#include <catch2/catch.hpp>
#include <core/procedural_generation.h>

using deviousdungeon::proceduralgeneration::ProceduralGeneration;

TEST_CASE("Board Generation", "[procedural][board]") {
  ProceduralGeneration procedural_generation;
  vector<vector<Tile*>> board_ = procedural_generation.GenerateRandomBoard(5,5);

  bool has_spawn = false;
  bool has_portal = false;

  for (vector<Tile*> row : board_) {
    for (Tile* tile : row) {
      if (tile->GetTileType() == deviousdungeon::tile::kPortalTile) {
        has_portal = true;
      }
      if (tile->GetTileType() == deviousdungeon::tile::kSpawnTile) {
        has_spawn = true;
      }
    }
  }

  assert(has_spawn == true);
  assert(has_portal == true);
}