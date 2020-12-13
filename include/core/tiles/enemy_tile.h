#pragma once

#include "cinder/gl/gl.h"
#include "core/tiles/tile.h"
#include "core/enemy.h"

using deviousdungeon::tile::Tile;
using deviousdungeon::enemy::Enemy;

namespace deviousdungeon {
namespace tile {
class EnemyTile : public Tile {
 public:
  EnemyTile() = default;
  EnemyTile(Enemy enemy);

  void OnEnter(Player& player);

  int GetValue() const;
  TileType GetTileType() override;
  ImageSourceRef GetImage() override;
  Enemy& GetEnemy();
 private:
  Enemy enemy_;
  TileType tile_type_ = kEnemy_Tile;
};
}//namespace tile
}//namespace deviousdungeon