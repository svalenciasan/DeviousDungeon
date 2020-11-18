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

size_t WeaponTile::GetWeaponPower() {
  return weapon_.GetPower();
}

TileType WeaponTile::GetTileType() {
  return tile_type_;
}

ImageSourceRef WeaponTile::GetImage() {
  if (weapon_.GetType() == weapon::kMeleeWeapon) {
    return ci::loadImage("weapons/Sword.png");
  } else {
    return ci::loadImage("weapons/Bow.png");
  }
}
}//namespace tile
}//namespace deviousdungeon