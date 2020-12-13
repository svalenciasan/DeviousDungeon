#include "core/tiles/enemy_tile.h"

using deviousdungeon::tile::Tile;
using deviousdungeon::tile::EnemyTile;
using deviousdungeon::enemy::Enemy;

namespace deviousdungeon {
namespace tile {
EnemyTile::EnemyTile(Enemy enemy) {
  enemy_ = enemy;
  if (enemy_.GetPower() >= 10) {
    tile_type_ = kBoss_Tile;
  }
}

void EnemyTile::OnEnter(Player& player) {
  player.UseMelee(enemy_);
}

int EnemyTile::GetValue() const{
  return enemy_.GetPower();
}

Enemy& EnemyTile::GetEnemy() {
  return enemy_;
}

TileType EnemyTile::GetTileType() {
  return tile_type_;
}

ImageSourceRef EnemyTile::GetImage() {
  if (enemy_.GetPower() <= 0) {
    return ci::loadImage("Clear.png");
  } else if (tile_type_ == kEnemy_Tile){
    return ci::loadImage("enemies/Hyena.png");
  } else {
    return ci::loadImage("enemies/Boss.png");
  }
}
}//namespace tile
}//namespace deviousdungeon