#pragma once

#include "cinder/gl/gl.h"
#include "tile.h"

using deviousdungeon::tile::Tile;

namespace deviousdungeon {
namespace tile {
class PortalTile : public Tile {
 public:
  PortalTile() = default;
  TileType GetTileType();
  ImageSourceRef GetImage();
  void OnEnter(Player& player);
 private:
  TileType tile_type_ = kPortalTile;
};
}//namespace deviousdungeon
}//namespace player