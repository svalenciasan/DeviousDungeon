#include <visualizer/tile_board.h>

namespace deviousdungeon {

namespace visualizer {

TileBoard::TileBoard(const vec2& top_left_corner, const vec2& bottom_right_corner, GameBoard& game_board) {
  top_left_corner_ = top_left_corner;
  bottom_right_corner_ = bottom_right_corner;
  game_board_ = &game_board;
  //tile_pixel_length_ = (bottom_right_corner_.x - top_left_corner_.x) / game_board_->GetColumns();
  tile_pixel_length_ = (bottom_right_corner_.y - top_left_corner_.y) / game_board_->GetRows();
  font_ = ci::Font("", 20);
}
void TileBoard::Update() {

}

void TileBoard::UpdateBounds(vec2 top_left_corner, vec2 bottom_right_corner) {
  top_left_corner_ = top_left_corner;
  bottom_right_corner_ = bottom_right_corner;
}

void TileBoard::Draw() const {
  vector<vector<Tile*>> board = game_board_->GetBoard();
  for (size_t row = 0; row < board.size(); row++) {
    for (size_t column = 0; column < board.size(); column++) {
      vec2 top_left_picture_bound = top_left_corner_ + vec2(column * tile_pixel_length_,row * tile_pixel_length_);
      vec2 bottom_right_picture_bound = vec2(top_left_corner_.x + tile_pixel_length_, top_left_corner_.y) + vec2(column * tile_pixel_length_,row * tile_pixel_length_ + tile_pixel_length_);
      ci::Rectf picture_bounds(top_left_picture_bound, bottom_right_picture_bound);
//      ci::gl::drawStrokedRect(picture_bounds);
      ci::gl::draw(ci::gl::Texture2d::create(board[row][column]->GetImage()), picture_bounds);
      //Draws power/heal/gold amount
      switch (board[row][column]->GetTileType()) {
        case tile::kWeapon_Tile: {
          WeaponTile *weapon_tile = static_cast<WeaponTile *>(board[row][column]);
          int value = weapon_tile->GetValue();
          string value_str = std::to_string(value);

//          texture_font_->drawString(value_str, bottom_right_picture_bound);
          ci::gl::drawStringRight(value_str, bottom_right_picture_bound + vec2(0, -20), ci::Color("black"), font_);
          break;
        }

        case tile::kBoss_Tile: {
          EnemyTile *enemy_tile = static_cast<EnemyTile *>(board[row][column]);
          int value = enemy_tile->GetValue();
          string value_str = std::to_string(value);

          //texture_font_->drawString(value_str, bottom_right_picture_bound);
          ci::gl::drawStringRight(value_str, bottom_right_picture_bound + vec2(0, -20), ci::Color("black"), font_);
          break;
        }

        case tile::kEnemy_Tile: {
          EnemyTile *enemy_tile = static_cast<EnemyTile *>(board[row][column]);
          int value = enemy_tile->GetValue();
          string value_str = std::to_string(value);

          //texture_font_->drawString(value_str, bottom_right_picture_bound);
          ci::gl::drawStringRight(value_str, bottom_right_picture_bound + vec2(0, -20), ci::Color("black"), font_);
          break;
        }

        case tile::kGold_Tile: {
          GoldTile *gold_tile = static_cast<GoldTile *>(board[row][column]);
          int value = gold_tile->GetValue();
          string value_str = std::to_string(value);

          //texture_font_->drawString(value_str, bottom_right_picture_bound);
          ci::gl::drawStringRight(value_str, bottom_right_picture_bound + vec2(0, -20), ci::Color("black"), font_);
          break;
        }

        case tile::kHealth_Tile: {
          HealthTile *health_tile = static_cast<HealthTile *>(board[row][column]);
          int value = health_tile->GetValue();
          string value_str = std::to_string(value);

          //texture_font_->drawString(value_str, bottom_right_picture_bound);
          ci::gl::drawStringRight(value_str, bottom_right_picture_bound + vec2(0, -20), ci::Color("black"), font_);
          break;
        }
      }
      //Draws player
      if (game_board_->GetPlayerLocation() == vec2(column, row)) {
        ci::gl::draw(ci::gl::Texture2d::create(ci::loadImage("player/Player.png")), picture_bounds);
      }
    }
  }
}

void TileBoard::HandleMovement(gameboard::Direction direction) {
  game_board_->Move(direction);
}

void TileBoard::HandleRanged(vec2 position) {
  vec2 board_coords =
      ((position - top_left_corner_) / (float)tile_pixel_length_);
      (position - top_left_corner_) / (float)tile_pixel_length_;
  board_coords = vec2(floor(board_coords.x), floor(board_coords.y));
  game_board_->RangedAttack(board_coords);
}
}//namespace visualizer

}//namespace deviousdungeon
