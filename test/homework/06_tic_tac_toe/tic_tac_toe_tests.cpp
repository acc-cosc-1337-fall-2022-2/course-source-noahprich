#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over if >9 slots selected") {
    vector<int> tester{1,2,3,4,5,7,6,9,8};
    TicTacToe game;
    game.start_game("X");
    for (int i = 0; i<8; i++) {
        game.mark_board(tester[i]-1);
        REQUIRE(game.game_over() == false);
    }
    game.mark_board(tester[8]-1);
    REQUIRE(game.game_over() == true);
    string play_again = "N";
}
