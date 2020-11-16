#pragma once

#include "cinder/gl/gl.h"
#include "tile.h"

using deviousdungeon::tile::Tile;

namespace deviousdungeon {
namespace tile {
class SpawnTile : public Tile {
 public:
  SpawnTile() = default;

  TileType GetTileType() override;
  ImageSourceRef GetImage() override;
 private:
  TileType tile_type_ = kSpawnTile;
};
}//namespace tile
}//namespace deviousdungeon