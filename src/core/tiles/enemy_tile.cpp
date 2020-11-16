#include "core/tiles/enemy_tile.h"

using deviousdungeon::tile::Tile;
using deviousdungeon::tile::EnemyTile;
using deviousdungeon::enemy::Enemy;

namespace deviousdungeon {
namespace tile {
//EnemyTile::EnemyTile() {
//  enemy_ = Enemy();
//}
EnemyTile::EnemyTile(Enemy enemy) {
  enemy_ = enemy;
}

TileType EnemyTile::GetTileType() {
  return tile_type_;
}

ImageSourceRef EnemyTile::GetImage() {
  return ci::loadImage("Hyena.png");
}
}//namespace tile
}//namespace deviousdungeon