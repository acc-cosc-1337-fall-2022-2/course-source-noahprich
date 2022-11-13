//h
#include "tic_tac_toe.h"
#ifndef TICTACTOEMANAGER_H
#define TICTACTOEMANAGER_H

class TicTacToeManager
{
public:
friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
void save_game(TicTacToe b);
void get_winner_total(int& o, int& w, int& t);//seems like w should be x, but instructions said.

private:
    vector<TicTacToe> games;
    int x_win=0;
    int o_win=0;
    int ties=0;
    void update_winner_count(string winner);
};

#endif