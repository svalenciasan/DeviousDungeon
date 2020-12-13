#include "core/enemy.h"

namespace deviousdungeon {
namespace enemy {
Enemy::Enemy() {
  power_ = rand() % 1 + 7;
}

Enemy::Enemy(int power) {
  power_ = power;
}

int Enemy::GetPower() const{
  return power_;
}

int Enemy::SetPower(int power) {
  power_ = power;
  return power_;
}
}//namespace enemy

}//namespace deviousdungeon
