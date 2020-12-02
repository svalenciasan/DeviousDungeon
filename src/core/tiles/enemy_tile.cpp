#include "core/tiles/enemy_tile.h"

using deviousdungeon::tile::Tile;
using deviousdungeon::tile::EnemyTile;
using deviousdungeon::enemy::Enemy;

namespace deviousdungeon {
namespace tile {
EnemyTile::EnemyTile(Enemy enemy) {
  enemy_ = enemy;
}

void EnemyTile::OnEnter(Player& player) {
  player.UseMelee(enemy_);
}

int EnemyTile::GetValue() const{
  return enemy_.GetPower();
}

TileType EnemyTile::GetTileType() {
  return tile_type_;
}

ImageSourceRef EnemyTile::GetImage() {
  return ci::loadImage("enemies/Hyena.png");
}
}//namespace tile
}//namespace deviousdungeon