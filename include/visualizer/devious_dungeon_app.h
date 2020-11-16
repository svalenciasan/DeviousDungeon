#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "tile_board.h"

namespace deviousdungeon {

namespace visualizer {

class DeviousDungeonApp : public ci::app::App {
 public:
  DeviousDungeonApp();
  void update() override;
  void draw() override;
  void keyDown(ci::app::KeyEvent event) override;
 private:
  const double kWindowSize = 900;
  const double kSideMargin = kWindowSize * .15;
  const double kUpperMargin = kWindowSize * .12;
  const double kLowerMargin = kWindowSize * .18;
  TileBoard tile_board_;
};

}//namespace visualizer

}//namespace deviousdungeon
