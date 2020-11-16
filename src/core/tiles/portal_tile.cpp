#include "core/tiles/portal_tile.h"

using deviousdungeon::tile::Tile;
using deviousdungeon::tile::PortalTile;

namespace deviousdungeon {
namespace tile {
TileType PortalTile::GetTileType() {
  return tile_type_;
}

ImageSourceRef PortalTile::GetImage() {
  return ci::loadImage("other/Portal.png");
}
}//namespace tile
}//namespace deviousdungeon