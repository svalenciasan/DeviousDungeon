#include "core/tiles/empty_tile.h"

using deviousdungeon::tile::Tile;
using deviousdungeon::tile::EmptyTile;

namespace deviousdungeon {
namespace tile {
TileType EmptyTile::GetTileType() {
  return tile_type_;
}

ImageSourceRef EmptyTile::GetImage() {
  return ci::loadImage("other/Empty.png");
}
}//namespace tile
}//namespace deviousdungeon