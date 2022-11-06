#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("test first player set to X") {
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("test first player set to O") {
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test game over if >9 slots selected and no winner") {
//    instructions are to use 1,2,3,4,5,6,7,8,9 which will make X the winner
//    at the 7th turn, so i'm going to use the original number sequence from last lab
    vector<int> tester{1,2,3,4,5,7,6,9,8};
    TicTacToe game;
    game.start_game("X");
    for (int i = 0; i<9; i++) {
        game.mark_board(tester[i]-1);
    }
    game.game_over();
    REQUIRE(game.get_winner() == "C");
    string play_again = "N";
}

TEST_CASE("test win by first column") {
    vector<int> tester{1,2,4,5,7,8,6,9,3};
    int i = 0;
    TicTacToe game;
    game.start_game("X");
    while (!game.game_over()) {
        game.mark_board(tester[i]-1);
        i++;
    }
    REQUIRE(game.get_winner() == "X");
    string play_again = "N";
}

TEST_CASE("test win by second column") {
    vector<int> tester{2,1,5,3,8};
    int i = 0;
    TicTacToe game;
    game.start_game("X");
    while (!game.game_over()) {
        game.mark_board(tester[i]-1);
        i++;
    }
    REQUIRE(game.get_winner() == "X");
    string play_again = "N";
}

TEST_CASE("test win by third column") {
    vector<int> tester{3,1,6,2,9};
    int i = 0;
    TicTacToe game;
    game.start_game("X");
    while (!game.game_over()) {
        game.mark_board(tester[i]-1);
        i++;
    }
    REQUIRE(game.get_winner() == "X");
    string play_again = "N";
}

TEST_CASE("test win by first row") {
    vector<int> tester{1,4,2,5,3};
    int i = 0;
    TicTacToe game;
    game.start_game("X");
    while (!game.game_over()) {
        game.mark_board(tester[i]-1);
        i++;
    }
    REQUIRE(game.get_winner() == "X");
    string play_again = "N";
}

TEST_CASE("test win by second row") {
    vector<int> tester{4,1,5,2,6};
    int i = 0;
    TicTacToe game;
    game.start_game("X");
    while (!game.game_over()) {
        game.mark_board(tester[i]-1);
        i++;
    }
    REQUIRE(game.get_winner() == "X");
    string play_again = "N";
}

TEST_CASE("test win by third row") {
    vector<int> tester{7,1,8,1,9};
    int i = 0;
    TicTacToe game;
    game.start_game("X");
    while (!game.game_over()) {
        game.mark_board(tester[i]-1);
        i++;
    }
    REQUIRE(game.get_winner() == "X");
    string play_again = "N";
}

TEST_CASE("test win diagonally from top left ") {
    vector<int> tester{1,2,5,3,9};
    int i = 0;
    TicTacToe game;
    game.start_game("X");
    while (!game.game_over()) {
        game.mark_board(tester[i]-1);
        i++;
    }
    REQUIRE(game.get_winner() == "X");
    string play_again = "N";
}

TEST_CASE("test win diagonally from bottom left ") {
    vector<int> tester{7,1,5,2,3};
    int i = 0;
    TicTacToe game;
    game.start_game("X");
    while (!game.game_over()) {
        game.mark_board(tester[i]-1);
        i++;
    }
    REQUIRE(game.get_winner() == "X");
    string play_again = "N";
}