#pragma once

#include "cinder/gl/gl.h"
#include "tile.h"
#include "enemy.h"

using deviousdungeon::tile::Tile;
using deviousdungeon::enemy::Enemy;

namespace deviousdungeon {
namespace tile {
class EnemyTile : public Tile {
 public:
  EnemyTile();
  EnemyTile(Enemy enemy);
  void OnEnter(Player& player);
  TileType GetTileType();
 private:
  Enemy enemy_;
  TileType tile_type_ = kEnemy_Tile;
};
}//namespace deviousdungeon
}//namespace player