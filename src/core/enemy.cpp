#include "core/enemy.h"

namespace deviousdungeon {
namespace enemy {
Enemy::Enemy() {
  power_ = rand() % 1 + 7;
}

Enemy::Enemy(size_t power) {
  power_ = power;
}

size_t Enemy::GetPower() {
  return power_;
}

size_t Enemy::SetPower(size_t power) {
  power_ -= power;
  return power_;
}
}//namespace enemy

}//namespace deviousdungeon
