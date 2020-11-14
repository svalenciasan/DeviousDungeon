#include "core/portal_tile.h"

using deviousdungeon::tile::Tile;
using deviousdungeon::tile::PortalTile;

namespace deviousdungeon {
namespace tile {
TileType PortalTile::GetTileType() {
  return tile_type_;
}
}
}