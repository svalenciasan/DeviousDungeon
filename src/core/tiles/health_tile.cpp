#include "core/tiles/health_tile.h"

using deviousdungeon::tile::Tile;
using deviousdungeon::tile::HealthTile;

namespace deviousdungeon {
namespace tile {
HealthTile::HealthTile() {
  heal_ = rand() % 1 + 7;
}
HealthTile::HealthTile(size_t heal) {
  heal_ = heal;
}

TileType HealthTile::GetTileType() {
  return tile_type_;
}

ImageSourceRef HealthTile::GetImage() {
  return ci::loadImage("collectibles/Potion.png");
}
}//namespace tile
}//namespace deviousdungeon