#include <catch2/catch.hpp>
#include <core/enemy.h>

using deviousdungeon::gameboard::GameBoard;

TEST_CASE("Board Generation", "[procedural][board]") {
  SECTION("Constructor") {
    GameBoard game_board(5, 5);
  }
}