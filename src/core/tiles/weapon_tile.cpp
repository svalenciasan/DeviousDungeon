#include "core/tiles/weapon_tile.h"

using deviousdungeon::tile::Tile;
using deviousdungeon::tile::WeaponTile;

namespace deviousdungeon {
namespace tile {
WeaponTile::WeaponTile() {
  weapon_ = Weapon(weapon::kMeleeWeapon);
}
WeaponTile::WeaponTile(Weapon weapon) {
  weapon_ = Weapon();
}

TileType WeaponTile::GetTileType() {
  return tile_type_;
}

ImageSourceRef WeaponTile::GetImage() {
  if ((rand() % 10) % 2 == 0) {
    return ci::loadImage("weapons/Sword.png");
  } else {
    return ci::loadImage("weapons/Bow.png");
  }
}
}//namespace tile
}//namespace deviousdungeon