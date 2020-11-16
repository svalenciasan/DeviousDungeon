#include <visualizer/devious_dungeon_app.h>

namespace deviousdungeon {

namespace visualizer {
DeviousDungeonApp::DeviousDungeonApp() {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
  tile_board_ = TileBoard(vec2(kSideMargin, kUpperMargin),
                          vec2(kWindowSize - kSideMargin, kWindowSize - kLowerMargin));
}

void DeviousDungeonApp::update() {

}

void DeviousDungeonApp::draw() {
  //Dark blue-purple
  ci::Color8u background_color(96, 96, 86);
  ci::gl::clear(background_color);

  tile_board_.Draw();
}

void DeviousDungeonApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_w:
      break;

    case ci::app::KeyEvent::KEY_s:

      break;

    case ci::app::KeyEvent::KEY_a:
      break;

    case ci::app::KeyEvent::KEY_d:
      break;
  }
}
}//namespace visualizer

}// namespace deviousdungeon
