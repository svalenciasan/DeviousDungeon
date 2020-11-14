#pragma once

#include "cinder/gl/gl.h"
#include "tile.h"

using deviousdungeon::tile::Tile;

namespace deviousdungeon {
namespace tile {
class EmptyTile : public Tile {
 public:
  EmptyTile();
  void OnEnter(Player& player);
  TileType GetTileType();
 private:
  TileType tile_type_ = kEmpty_Tile;
};
}//namespace deviousdungeon
}//namespace player