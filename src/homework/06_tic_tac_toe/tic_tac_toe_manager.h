//h
#include <memory>
#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"
#ifndef TICTACTOEMANAGER_H
#define TICTACTOEMANAGER_H

class TicTacToeManager
{
//note: tests will update save game file with test games when run.
public:
    TicTacToeManager()=default;
    TicTacToeManager(TicTacToeData &data1);//constructor defined in cpp
    ~TicTacToeManager();//destructor defined in cpp
    friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
    void save_game(std::unique_ptr<TicTacToe> &b);// note: the instructions on how to set up save game function mean that the tests will also update winner counts, 
    void get_winner_total(int& o, int& w, int& t);//seems like w should be x, but instructions said.
    
private:
    vector<std::unique_ptr<TicTacToe>> games;
    int x_win=0;
    int o_win=0;
    int ties=0;
    void update_winner_count(string winner);
    TicTacToeData data;
};

#endif