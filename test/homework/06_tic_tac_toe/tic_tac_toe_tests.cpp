#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X")
{
	TicTacToe game;
	game.start_game("X");
	REQUIRE(game.get_player()=="X");
}
TEST_CASE("Test first player set to O")
{
	TicTacToe game;
	game.start_game("O");
	REQUIRE(game.get_player()=="O");
}
TEST_CASE("Test game over if 9 slots are selected")
{
	TicTacToe game; 
	game.start_game("X");
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(3);
	REQUIRE(game.game_over()==false);
	game.mark_board(4);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(7);
	REQUIRE(game.game_over()==false);
	game.mark_board(6);
	REQUIRE(game.game_over()==false);
	game.mark_board(9);
	REQUIRE(game.game_over()==false);
	game.mark_board(8);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="C");
	
}
TEST_CASE("Test win by first column")
{
	TicTacToe game; 
	game.start_game("X");
	game.mark_board(1);//1 for x
	REQUIRE(game.game_over()==false);
	game.mark_board(2);//2 for o
	REQUIRE(game.game_over()==false);
	game.mark_board(4);//4 for x
	REQUIRE(game.game_over()==false);
	game.mark_board(5);//5 for o
	REQUIRE(game.game_over()==false);
	game.mark_board(7);//7 for x
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}

TEST_CASE("Test win by second column")
{
	TicTacToe game; 
	game.start_game("X");
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(4);
	REQUIRE(game.game_over()==false);
	game.mark_board(8);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}

TEST_CASE("Test win by third column")
{
	TicTacToe game; 
	game.start_game("X");
	game.mark_board(3);
	REQUIRE(game.game_over()==false);
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(6);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(9);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}
TEST_CASE("Test win by first row")
{
	TicTacToe game; 
	game.start_game("X");
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(7);
	REQUIRE(game.game_over()==false);
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(4);
	REQUIRE(game.game_over()==false);
	game.mark_board(3);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}
TEST_CASE("Test win by second row")
{
	TicTacToe game; 
	game.start_game("X");
	game.mark_board(4);
	REQUIRE(game.game_over()==false);
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(6);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}
TEST_CASE("Test win by third row")
{
	TicTacToe game; 
	game.start_game("X");
	game.mark_board(7);
	REQUIRE(game.game_over()==false);
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(8);
	REQUIRE(game.game_over()==false);
	game.mark_board(6);
	REQUIRE(game.game_over()==false);
	game.mark_board(9);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}

TEST_CASE("Test win diagonally from top left")
{
	TicTacToe game; 
	game.start_game("X");
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(7);
	REQUIRE(game.game_over()==false);
	game.mark_board(9);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}

TEST_CASE("Test win diagonally from bottom left")
{
	TicTacToe game; 
	game.start_game("X");
	game.mark_board(7);
	REQUIRE(game.game_over()==false);
	game.mark_board(8);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(3);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="X");
}

TEST_CASE("Test TicTacToe manager get winner total function")
{
	TicTacToe game; // tie game
	TicTacToeManager manager;
	game.start_game("X");
	game.mark_board(1);
	REQUIRE(game.game_over()==false);
	game.mark_board(2);
	REQUIRE(game.game_over()==false);
	game.mark_board(3);
	REQUIRE(game.game_over()==false);
	game.mark_board(4);
	REQUIRE(game.game_over()==false);
	game.mark_board(5);
	REQUIRE(game.game_over()==false);
	game.mark_board(7);
	REQUIRE(game.game_over()==false);
	game.mark_board(6);
	REQUIRE(game.game_over()==false);
	game.mark_board(9);
	REQUIRE(game.game_over()==false);
	game.mark_board(8);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner()=="C");//require c for "call it a tie". this set of potitions is a tie.
	manager.save_game(game);

	TicTacToe game1; // x win 1
	game1.start_game("X");
	game1.mark_board(1);//1 for x
	REQUIRE(game1.game_over()==false);
	game1.mark_board(2);//2 for o
	REQUIRE(game1.game_over()==false);
	game1.mark_board(4);//4 for x
	REQUIRE(game1.game_over()==false);
	game1.mark_board(5);//5 for o
	REQUIRE(game1.game_over()==false);
	game1.mark_board(7);//7 for x
	REQUIRE(game1.game_over()==true);
	REQUIRE(game1.get_winner()=="X");
	manager.save_game(game1);


	TicTacToe game2; // o first win
	game2.start_game("O");
	game2.mark_board(1);//1 for o
	REQUIRE(game2.game_over()==false);
	game2.mark_board(2);//2 for x
	REQUIRE(game2.game_over()==false);
	game2.mark_board(4);//4 for o
	REQUIRE(game2.game_over()==false);
	game2.mark_board(5);//5 for x
	REQUIRE(game2.game_over()==false);
	game2.mark_board(7);//7 for o
	REQUIRE(game2.game_over()==true);
	REQUIRE(game2.get_winner()=="O");
	manager.save_game(game2);


	TicTacToe game3; //o second win
	game3.start_game("O");
	game3.mark_board(1);//1 for o
	REQUIRE(game3.game_over()==false);
	game3.mark_board(2);//2 for x
	REQUIRE(game3.game_over()==false);
	game3.mark_board(4);//4 for o
	REQUIRE(game3.game_over()==false);
	game3.mark_board(5);//5 for x
	REQUIRE(game3.game_over()==false);
	game3.mark_board(7);//7 for o
	REQUIRE(game3.game_over()==true);
	REQUIRE(game3.get_winner()=="O");
	manager.save_game(game3);


	TicTacToe game4; //o third win
	game4.start_game("O");
	game4.mark_board(1);//1 for o
	REQUIRE(game4.game_over()==false);
	game4.mark_board(2);//2 for x
	REQUIRE(game4.game_over()==false);
	game4.mark_board(4);//4 for o
	REQUIRE(game4.game_over()==false);
	game4.mark_board(5);//5 for x
	REQUIRE(game4.game_over()==false);
	game4.mark_board(7);//7 for o
	REQUIRE(game4.game_over()==true);
	REQUIRE(game4.get_winner()=="O");
	manager.save_game(game4);



	
	TicTacToe game5; //x second win
	game5.start_game("X");
	game5.mark_board(1);//1 for x
	REQUIRE(game5.game_over()==false);
	game5.mark_board(2);//2 for o
	REQUIRE(game5.game_over()==false);
	game5.mark_board(4);//4 for x
	REQUIRE(game5.game_over()==false);
	game5.mark_board(5);//5 for o
	REQUIRE(game5.game_over()==false);
	game5.mark_board(7);//7 for x
	REQUIRE(game5.game_over()==true);
	REQUIRE(game5.get_winner()=="X");
	manager.save_game(game5);

// 6 games played(0-5). 1 tie, 2 wins for X, 3 wins for O. 

	int x_win;
	int o_win;
	int ties;
	manager.get_winner_total( o_win,x_win,ties);
	REQUIRE(x_win==2);//let x win 2 time 
	REQUIRE(o_win==3); // let o win 3 time to differentiate tallies.
	REQUIRE(ties==1);//tie once
}