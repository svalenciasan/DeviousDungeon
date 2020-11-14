#pragma once

#include "cinder/gl/gl.h"

namespace deviousdungeon {
namespace enemy {
class Enemy {
 public:
  //Random enemy power.
  Enemy();
  Enemy(size_t power);
  size_t GetPower();
  size_t SetPower();
 private:
  size_t power_;
};
}//namespace deviousdungeon
}//namespace enemy