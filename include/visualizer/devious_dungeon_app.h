#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/TextureFont.h"
#include "cinder/gl/gl.h"
#include "cinder/audio/audio.h"
#include "cinder/app/RendererGl.h"
#include "cinder/app/App.h"
#include "vector"
#include "tile_board.h"

namespace deviousdungeon {

namespace visualizer {

class DeviousDungeonApp : public ci::app::App {
 public:
  DeviousDungeonApp();
  void update() override;
  void draw() override;
  void keyDown(ci::app::KeyEvent event) override;
  void mouseDown(ci::app::MouseEvent event) override;
 private:
  const double kWindowSize = 900;
  const double kSideMargin = kWindowSize * .15;
  const double kUpperMargin = kWindowSize * .12;
  const double kLowerMargin = kWindowSize * .18;
  //Game board amount of squares.
  size_t kBoardSize = 5;
  GameBoard game_board_;
  TileBoard tile_board_;

  //Private methods
  void DrawGameOver();
  void DrawWinningGame();
  void DrawUI();
  void DrawBottomUI(vec2 top_left, vec2 bottom_right);
};

}//namespace visualizer

}//namespace deviousdungeon
