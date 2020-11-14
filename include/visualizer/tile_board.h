#pragma once

#include "cinder/gl/gl.h"

namespace deviousdungeon {

namespace visualizer {

class TileBoard {
 public:
  TileBoard();

  void Update();

  void Draw() const;

 private:
};

}  // namespace visualizer

}  // namespace deviousdungeon
