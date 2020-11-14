#pragma once

#include "cinder/gl/gl.h"
#include "tile.h"

using deviousdungeon::tile::Tile;

namespace deviousdungeon {
namespace tile {
class WeaponTile : public Tile {
 public:
  //Random heal.
  WeaponTile();
  WeaponTile(Weapon weapon);
  void OnEnter(Player& player);
  TileType GetTileType();
 private:
  Weapon weapon_;
  TileType tile_type_ = kWeapon_Tile;
};
}//namespace deviousdungeon
}//namespace player