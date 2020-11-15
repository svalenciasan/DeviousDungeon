#include "core/enemy_tile.h"

using deviousdungeon::tile::Tile;
using deviousdungeon::tile::EnemyTile;

namespace deviousdungeon {
namespace tile {
EnemyTile::EnemyTile() {
  enemy_ = Enemy(rand() % 1 + 7);
}
EnemyTile::EnemyTile(Enemy enemy) {
  enemy_ = enemy;
}
}
}