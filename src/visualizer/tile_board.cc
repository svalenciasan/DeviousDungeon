#include <visualizer/tile_board.h>

namespace deviousdungeon {

namespace visualizer {
TileBoard::TileBoard(const vec2& top_left_corner, const vec2& bottom_right_corner) {
  top_left_corner_ = top_left_corner;
  bottom_right_corner_ = bottom_right_corner;
  game_board_ = GameBoard(board_size_, board_size_);
  tile_pixel_length_ = (bottom_right_corner_.x - top_left_corner_.x) / board_size_;
}
void TileBoard::Update() {

}
void TileBoard::Draw() const {
//  ci::Rectf pixel_bounding_box(top_left_corner_, bottom_right_corner_);
//
//  ci::gl::color(ci::Color("white"));
//  ci::gl::drawSolidRect(pixel_bounding_box);

  vector<vector<Tile*>> board = game_board_.GetBoard();
  for (size_t row = 0; row < board.size(); row++) {
    for (size_t column = 0; column < board.size(); column++) {
      vec2 top_left_picture_bound = top_left_corner_ + vec2(column * tile_pixel_length_,row * tile_pixel_length_);
      vec2 bottom_right_picture_bound = vec2(top_left_corner_.x + tile_pixel_length_, top_left_corner_.y) + vec2(column * tile_pixel_length_,row * tile_pixel_length_ + tile_pixel_length_);
      ci::Rectf picture_bounds(top_left_picture_bound, bottom_right_picture_bound);
      ci::gl::draw(ci::gl::Texture2d::create(board[row][column]->GetImage()), picture_bounds);
    }
  }

}
}//namespace visualizer

}//namespace deviousdungeon
