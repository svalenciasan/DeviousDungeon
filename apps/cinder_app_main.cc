#include <visualizer/devious_dungeon_app.h>

using deviousdungeon::visualizer::DeviousDungeonApp;

void prepareSettings(DeviousDungeonApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(DeviousDungeonApp, ci::app::RendererGl, prepareSettings);
