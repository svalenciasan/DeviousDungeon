#include <visualizer/devious_dungeon_app.h>

namespace deviousdungeon {

namespace visualizer {

DeviousDungeonApp::DeviousDungeonApp() {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
  game_board_ = GameBoard(kBoardSize,kBoardSize);
  tile_board_ = TileBoard(vec2(kSideMargin, kUpperMargin),
                          vec2(kWindowSize - kSideMargin, kWindowSize - kLowerMargin), game_board_);
}

void DeviousDungeonApp::update() {
  tile_board_.UpdateBounds(vec2(kSideMargin, kUpperMargin),
                           vec2(kWindowSize - kSideMargin, kWindowSize - kLowerMargin));
}

void DeviousDungeonApp::draw() {
  //Dark blue-purple
  //ci::Color8u background_color(96, 96, 86);
  ci::Color8u background_color(255, 178, 102);
  ci::gl::clear(background_color);
  if(game_board_.GetGameState() == gameboard::kInProgress) {
    tile_board_.Draw();
    DrawUI();
  } else if(game_board_.GetGameState() == gameboard::kGameOver) {
    DrawGameOver();
  } else if (game_board_.GetGameState() == gameboard::kWinGame) {
    DrawWinningGame();
  }
}

void DeviousDungeonApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_w:
      tile_board_.HandleMovement(gameboard::kUp);
      break;

    case ci::app::KeyEvent::KEY_s:
      tile_board_.HandleMovement(gameboard::kDown);
      break;

    case ci::app::KeyEvent::KEY_a:
      tile_board_.HandleMovement(gameboard::kLeft);
      break;

    case ci::app::KeyEvent::KEY_d:
      tile_board_.HandleMovement(gameboard::kRight);
      break;
  }
}

void DeviousDungeonApp::mouseDown(ci::app::MouseEvent event) {
  tile_board_.HandleRanged(event.getPos());
}

/**
 * Private
 */

void DeviousDungeonApp::DrawGameOver() {
  auto font = ci::Font("", 100);
  ci::gl::drawStringCentered("Game Over", vec2(kWindowSize / 2, kUpperMargin), ci::Color("black"), font);
}

void DeviousDungeonApp::DrawWinningGame() {
  auto font = ci::Font("", 100);
  ci::gl::drawStringCentered("Win", vec2(kWindowSize / 2, kUpperMargin), ci::Color("black"), font);
}

void DeviousDungeonApp::DrawUI() {
  vec2 top_left(0, kWindowSize - kLowerMargin);
  vec2 bottom_right(kWindowSize, kWindowSize);

  ci::gl::color(ci::Color("beige"));
  ci::gl::drawSolidRect(ci::Rectf(top_left, bottom_right));
  //ci::gl::drawStrokedRect(ci::Rectf(top_left, bottom_right));

  auto font = ci::Font("", 30);
  ci::gl::drawStringRight("SCORE: " + std::to_string(game_board_.GetScore()), vec2(kWindowSize - kSideMargin, 50), ci::Color("black"), font);
  DrawBottomUI(vec2(0, kWindowSize - kLowerMargin), vec2(kWindowSize, kWindowSize));
}

void DeviousDungeonApp::DrawBottomUI(vec2 top_left, vec2 bottom_right) {
  double vertical_length = bottom_right.y - top_left.y;
  double horizontal_length = bottom_right.x - top_left.x;
  double vertical_margins = vertical_length * .05;
  double horizontal_margins = horizontal_length * .05;

  auto font = ci::Font("", 30);
  //LEVEL
  ci::gl::drawStringRight("LVL: " + std::to_string(game_board_.GetLevel()),
                          vec2(bottom_right.x - horizontal_margins, top_left.y + vertical_margins),
                          ci::Color("black"), font);
  //HEALTH COUNTER
  double heart_square_size = horizontal_length / 12;
  ImageSourceRef full_heart = ci::loadImage("player/FullHeart.png");
  ImageSourceRef empty_heart = ci::loadImage("player/EmptyHeart.png");

  vec2 top_left_heart_bound(top_left.x + horizontal_margins, top_left.y + vertical_length * .07);
  vec2 bottom_right_heart_bound = top_left_heart_bound + vec2(heart_square_size, heart_square_size);
  ci::Rectf picture_bounds(top_left_heart_bound, bottom_right_heart_bound);

  size_t health = game_board_.GetPlayer().GetHealth();
  size_t empty_health = game_board_.GetPlayer().GetMaxHealth() - health;
  while (health > 0) {
    ci::gl::draw(ci::gl::Texture2d::create(full_heart), picture_bounds);
    top_left_heart_bound += vec2(heart_square_size, 0);
    bottom_right_heart_bound += vec2(heart_square_size, 0);
    picture_bounds = ci::Rectf(top_left_heart_bound, bottom_right_heart_bound);
    health--;
  }
  while (empty_health > 0) {
    ci::gl::draw(ci::gl::Texture2d::create(empty_heart), picture_bounds);
    top_left_heart_bound += vec2(heart_square_size, 0);
    bottom_right_heart_bound += vec2(heart_square_size, 0);
    picture_bounds = ci::Rectf(top_left_heart_bound, bottom_right_heart_bound);
    empty_health--;
  }
  //WEAPON UI
  double equipped_weapon_size = horizontal_length / 12;
  ImageSourceRef melee_weapon = ci::loadImage("weapons/Sword.png");
  ImageSourceRef ranged_weapon = ci::loadImage("weapons/Bow.png");

  vec2 top_left_weapon_bound(top_left.x + horizontal_margins, top_left.y + vertical_length * .5);
  vec2 bottom_right_weapon_bound = top_left_weapon_bound + vec2(equipped_weapon_size, equipped_weapon_size);
  ci::Rectf weapon_bounds(top_left_weapon_bound, bottom_right_weapon_bound);

  Weapon melee = game_board_.GetPlayer().GetWeapon(weapon::kMeleeWeapon);
  Weapon ranged = game_board_.GetPlayer().GetWeapon(weapon::kRangedWeapon);

  if (melee.GetPower() > 0) {
    ci::gl::draw(ci::gl::Texture2d::create(melee_weapon), weapon_bounds);
    int value = melee.GetPower();
    string value_str = std::to_string(value);
    ci::gl::drawStringRight(value_str, bottom_right_weapon_bound + vec2(0, -20), ci::Color("black"), font);
  }
  if (ranged.GetPower() > 0) {
    top_left_weapon_bound += vec2(equipped_weapon_size * 1.5, 0);
    bottom_right_weapon_bound += vec2(equipped_weapon_size * 1.5, 0);
    weapon_bounds = ci::Rectf(top_left_weapon_bound, bottom_right_weapon_bound);

    ci::gl::draw(ci::gl::Texture2d::create(ranged_weapon), weapon_bounds);
    int value = ranged.GetPower();
    string value_str = std::to_string(value);
    ci::gl::drawStringRight(value_str, bottom_right_weapon_bound + vec2(0, -20), ci::Color("black"), font);
  }
}

}//namespace visualizer

}// namespace deviousdungeon
