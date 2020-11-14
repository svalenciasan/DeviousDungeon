#pragma once

#include "cinder/gl/gl.h"
#include "player.h"

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
  void OnEnter(Player& player);
  TileType GetTileType();
  ImageSourceRef GetImage();
 private:
};
}//namespace deviousdungeon
}//namespace player