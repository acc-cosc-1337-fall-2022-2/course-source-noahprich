#include "tic_tac_toe.h"
int main() 
{
    TicTacToe game;
    string first_player;
    int position;
    string play_again;
    do {
        cout << "Do you wish to play 'X' or 'O'?\n";
        cin >> first_player;
        game.start_game(first_player);
        while (!game.game_over()) {
            game.display_board();
            cin >> position;
            game.mark_board(position - 1);
        }
        cout << "\nGame over!\nPlay again? (Y/N)\n";
        cin >> play_again;
    }
    while (play_again == "Y");
    cout << "Thanks for playing! We will soon add functionality"
            " for win condition checks.";
	return 0;
}