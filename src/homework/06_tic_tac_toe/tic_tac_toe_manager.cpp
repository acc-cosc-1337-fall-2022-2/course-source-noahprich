//cpp
#include <iostream>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include<string>

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe> &b)
{
    update_winner_count(b->get_winner());
    games.push_back(std::move(b));
    
}
std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    for (int i = 0; i <manager.games.size();i++)
        {
            out<<"\n"<<*(manager.games[i])<<"\n";
        } 
    
    return out;
}
void TicTacToeManager::get_winner_total(int& o, int& w, int& t)
{
    o=o_win;
    w=x_win;//I assume that passed ref w was meant to be x(instruction typo?).
    t=ties;
}
void TicTacToeManager::update_winner_count(string winner)
{
    if (winner=="X")
        x_win+=1;
    else if (winner=="O")
        o_win+=1;
    else
        ties+=1;
}