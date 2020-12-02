#include <catch2/catch.hpp>
#include <core/game_board.h>

using deviousdungeon::gameboard::GameBoard;

TEST_CASE("Board Generation", "[procedural][board]") {
SECTION("Constructor") {
  GameBoard game_board(5, 5);
  size_t a = 5;
  size_t b = 9;
  auto g = a - b;
}
}