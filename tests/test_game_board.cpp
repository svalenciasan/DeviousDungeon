#include <catch2/catch.hpp>
#include <core/game_board.h>

using deviousdungeon::gameboard::GameBoard;

TEST_CASE("Board Generation", "[procedural][board]") {
  SECTION("Constructor") {
    GameBoard game_board(5, 5);
    assert(game_board.GetGameState() == deviousdungeon::gameboard::kInProgress);
    assert(game_board.GetLevel() == 1);
    assert(game_board.GetScore() == 0);
    assert(game_board.GetRows() == 5);
    assert(game_board.GetColumns() == 5);
    assert(game_board.GetPlayer().GetHealth() == 3);
  }
}
TEST_CASE("Movement", "move") {
  GameBoard game_board(5, 5);

}