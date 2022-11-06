#include "tic_tac_toe.h"
int main() 
{
    TicTacToe game;
    string first_player, play_again, winner;
    int position;
    do {
        cout << "Do you wish to play 'X' or 'O'?\n";
        cin >> first_player;
        game.start_game(first_player);
        while (!game.game_over()) {
            game.display_board();
            cin >> position;
            game.mark_board(position - 1);
        }
        winner = game.get_winner();
        cout << "Game over!";
        if (winner == "C") cout << " It's... a tie? Boring!";
        else cout << " And the winner is " << winner << "!\n";
        cout << "\n\nPlay again? (Y/N)\n";
        cin >> play_again;
    }
    while (toupper(play_again[0]) == 'Y');
    cout << "Thanks for playing!";
	return 0;
}