#pragma once

#include "cinder/gl/gl.h"
#include "core/player.h"

using cinder::vec2;
using cinder::ImageSourceRef;
using deviousdungeon::player::Player;

namespace deviousdungeon {
namespace tile {
enum TileType {
  kSpawnTile,
  kPortalTile,
  kEmpty_Tile,
  kEnemy_Tile,
  kWeapon_Tile,
  kHealth_Tile,
  kGold_Tile
};
class Tile {
 public:
  //void OnEnter(Player& player);
  virtual TileType GetTileType() = 0;
  virtual ImageSourceRef GetImage() = 0;
 private:
};
}//namespace tile
}//namespace deviousdungeon