#pragma once

#include "cinder/gl/gl.h"
#include "core/tiles/tile.h"

using deviousdungeon::tile::Tile;

namespace deviousdungeon {
namespace tile {
class WeaponTile : public Tile {
 public:
  //Random heal.
  WeaponTile();
  WeaponTile(Weapon weapon);

  void OnEnter(Player& player);
  TileType GetTileType() override;
  ImageSourceRef GetImage() override;
 private:
  Weapon weapon_;
  TileType tile_type_ = kWeapon_Tile;
};
}//namespace tile
}//namespace deviousdungeon