//h
#include <tic_tac_toe_3.h>
#include <tic_tac_toe_4.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <memory>
#include <memory>
#include <vector>
#include "tic_tac_toe.h"
#ifndef TICTACTOEDATA_H
#define TICTACTOEDATA_H

class TicTacToeData
{
public:
void save_games(const std::vector<std::unique_ptr<TicTacToe>>&games);






std::vector<std::unique_ptr<TicTacToe>>get_games();

private:



};
#endif