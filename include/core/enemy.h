#pragma once

#include "cinder/gl/gl.h"

namespace deviousdungeon {
namespace enemy {
class Enemy {
 public:
  //Random enemy power.
  Enemy();
  Enemy(int power);

  int GetPower() const;
  int SetPower(int power);

 private:
  int power_;
};
}//namespace enemy
}//namespace deviousdungeon