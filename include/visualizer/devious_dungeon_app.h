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
};

}//namespace visualizer

}//namespace deviousdungeon
