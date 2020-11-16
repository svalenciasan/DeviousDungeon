#include "core/tiles/gold_tile.h"

using deviousdungeon::tile::Tile;
using deviousdungeon::tile::GoldTile;

namespace deviousdungeon {
namespace tile {
GoldTile::GoldTile() {
  gold_ = rand() % 1 + 7;
}
GoldTile::GoldTile(size_t gold) {
  gold_ = gold;
}

TileType GoldTile::GetTileType() {
  return tile_type_;
}

ImageSourceRef GoldTile::GetImage() {
  return ci::loadImage("collectibles/Coins.png");
}
}//namespace tile
}//namespace deviousdungeon