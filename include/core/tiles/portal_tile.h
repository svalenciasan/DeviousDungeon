#pragma once

#include "cinder/gl/gl.h"
#include "core/tiles/tile.h"

using deviousdungeon::tile::Tile;

namespace deviousdungeon {
namespace tile {
class PortalTile : public Tile {
 public:
  PortalTile() = default;

  TileType GetTileType() override;
  ImageSourceRef GetImage() override;
 private:
  TileType tile_type_ = kPortalTile;
};
}//namespace tile
}//namespace deviousdungeon