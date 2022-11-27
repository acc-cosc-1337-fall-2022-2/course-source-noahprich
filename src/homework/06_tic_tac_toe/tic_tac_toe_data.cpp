//cpp
#include <tic_tac_toe_data.h>
#include <tic_tac_toe.h>
#include <tic_tac_toe_3.h>
#include <tic_tac_toe_4.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <memory>

void TicTacToeData::save_games(const std::vector<std::unique_ptr<TicTacToe>>&games)
{
    std::ofstream outputFile;
    outputFile.open("tic_tac_toe_file.txt");
    for (const auto &game:games)
       {
           vector<string> j=game->get_pegs();
           for (int i=0;i<j.size();i++)
        {
           outputFile<< j[i];
           
           
        }
        outputFile<<game->get_winner();
        outputFile<<"\n";
       }
    //outputFile.close(); instructions did not say to close file for save_games(but explicitly said to do so for get_games),so I did not include. Is there reason for this?
}










std::vector<std::unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
    vector<std::unique_ptr<TicTacToe>> boards;
    std::ifstream inputFile;
    inputFile.open("tic_tac_toe_file.txt");
    string line;
    while (getline(inputFile,line))
    {
        vector<string> pegs;
        for (int i=0; i<(line.size()-1);i++)//can't include last char, that's winner, so -1.
           {
            char f = line[i];
            string  x(1,f);
            pegs.push_back(x);
           }
           auto c=string(1,line[(line.size()-1)]);//get last char in c
        string winner=c;
        std::unique_ptr<TicTacToe> board;
        if (pegs.size()==9)
            {
            board = std::make_unique<TicTacToe3>(pegs, winner);
            
            }
        else if (pegs.size()==16)
        {
             board = std::make_unique<TicTacToe4>(pegs, winner);
        }

        
        boards.push_back(std::move(board));
    }
    inputFile.close();
    return boards;

}
