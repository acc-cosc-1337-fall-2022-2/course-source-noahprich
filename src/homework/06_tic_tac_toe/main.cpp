#include <memory>
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
#include <vector>
using std::unique_ptr;
using std::make_unique;
using std::cin;
int main() 
{
	TicTacToeData data;
	TicTacToeManager manager(data);
	LOOP: string player_choice;
	std::cout<<"do you want to play tictactoe 3 or 4? press 3 for tictactoe 3 and 4 for tictactoe 4: ";
	int player_choice0;
	cin>>player_choice0;
	unique_ptr<TicTacToe> game;
	//unique_ptr<TicTacToe> game=make_unique<TicTacToe3>();
	
	if(player_choice0==3)
		game=make_unique<TicTacToe3>();// instantiate
	else if(player_choice0==4)
		game=make_unique<TicTacToe4>();// instantiate
	else
	{
		goto LOOP;
	}
	
	//cannot be in overload. this cin is necessary to instantiate TicTacToe game class .
	std::cout<<"\n First Player! Please Enter (Capital) X or O:\t";//instructions specify capital  X or O not lowercase x or o, so I only allow those.
	std::cin>>player_choice;//cannot be in overload. this cin is necessary to instantiate TicTacToe game class .
	//std::cin.clear();
	
	if(player_choice!="X"&&player_choice!="O")//instructions say argument value must be X or O, so I Loop if not X or O.
		{
			std::cout<<"Enter (Capital) X or O to continue";
			goto LOOP;
		}

	game->start_game(player_choice);
	do //inner loop for marking board
	{	
		// take position and display board with overloaded operator.
		std::cin>>*game;//overloaded cin game
		std::cout<<*game;//overload cout game.
		if (game->game_over()==true)
			{
				string final_victor= game->get_winner();
				std::cout<<"\nThe Winner Is:\t"<<final_victor;
			}
	}
	while(game->game_over()==false);
	manager.save_game(game);//trying to dereference with * here causes error. I assume because save_game takes reference to unique_pointer
	std::cout<<"\nGame Over\n";
	int x_win;
	int o_win;
	int ties;
	manager.get_winner_total( o_win,x_win,ties);
	std::cout<<"\n\n"<<"Wins for X:\t"<<x_win<<"\nWins for O:\t"<<o_win<<"\nTied games:\t"<<ties;
	string continue_check;
	std::cout<<"\nDo you want to continue or exit? If you want to continue enter (Capital) Y. Enter any other key to exit:\t";
	std::cin>>continue_check;
	if(continue_check=="Y")//if input ==Y, control will go to beginning, clear board and begin game again.
		goto LOOP;
	std::cout<<manager;//manager overload ostream cout.
	
	int x_wins;
	int o_wins;
	int tiess;
	manager.get_winner_total( o_wins,x_wins,tiess);
	std::cout<<"\n"<<"Wins for X:\t"<<x_wins<<"\nWins for O:\t"<<o_wins<<"\nTied games:\t"<<tiess;
	return 0;
}