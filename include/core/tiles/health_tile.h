#pragma once

#include "cinder/gl/gl.h"
#include "core/tiles/tile.h"

using deviousdungeon::tile::Tile;

namespace deviousdungeon {
namespace tile {
class HealthTile : public Tile {
 public:
  //Random heal.
  HealthTile();
  HealthTile(size_t heal);

  void OnEnter(Player& player);
  size_t GetHeal();
  TileType GetTileType() override;
  ImageSourceRef GetImage() override;
 private:
  size_t heal_;
  TileType tile_type_ = kHealth_Tile;
};
}//namespace deviousdungeon
}//namespace tile