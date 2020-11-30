#pragma once

#include "cinder/gl/gl.h"
#include "cinder/Font.h"
#include "core/game_board.h"
#include <iostream>
#include <string>

using std::string;
using deviousdungeon::gameboard::GameBoard;
//using ci::gl::Texture;

namespace deviousdungeon {

namespace visualizer {

class TileBoard {
 public:
  TileBoard() = default;

  TileBoard(const vec2& top_left_corner, const vec2& bottom_right_corner);

  void Update();

  void Draw() const;

  void HandleMovement(gameboard::Direction direction);
 private:
  vec2 top_left_corner_;
  vec2 bottom_right_corner_;
  size_t board_size_ = 5;
  GameBoard game_board_;
  double tile_pixel_length_;
};

}  // namespace visualizer

}  // namespace deviousdungeon
