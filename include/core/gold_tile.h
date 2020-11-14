#pragma once

#include "cinder/gl/gl.h"
#include "tile.h"

using deviousdungeon::tile::Tile;

namespace deviousdungeon {
namespace tile {
class GoldTile : public Tile {
 public:
  //Random gold.
  GoldTile();
  GoldTile(size_t gold);
  void OnEnter(Player& player);
  TileType GetTileType();
 private:
  size_t gold_;
  TileType tile_type_ = kGold_Tile;
};
}//namespace deviousdungeon
}//namespace player