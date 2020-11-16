#pragma once

#include "cinder/gl/gl.h"
#include "core/tiles/tile.h"

using deviousdungeon::tile::Tile;

namespace deviousdungeon {
namespace tile {
class EmptyTile : public Tile {
 public:
  EmptyTile() = default;

  TileType GetTileType() override;
  ImageSourceRef GetImage() override;
 private:
  TileType tile_type_ = kEmpty_Tile;
};
}//namespace tile
}//namespace deviousdungeon