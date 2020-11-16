#include "core/tiles/spawn_tile.h"

using deviousdungeon::tile::Tile;
using deviousdungeon::tile::SpawnTile;

namespace deviousdungeon {
namespace tile {
TileType SpawnTile::GetTileType() {
  return tile_type_;
}

ImageSourceRef SpawnTile::GetImage() {
  return ci::loadImage("Mummy.png");
}
}//namespace tile
}//namespace deviousdungeon