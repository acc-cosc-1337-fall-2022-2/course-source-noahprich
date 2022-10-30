//h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TicTacToe {
    vector<string> pegs{" "," "," "," "," "," "," "," "," "};
    string player;

public:
    string choices = "123456789";
    bool game_over();
    void start_game(string first_player);
    void mark_board(int position);
    bool check_section(int position);
    string get_player() const;
    void display_board() const;

private:
    void set_next_player();
    bool check_board_full();
    void clear_board();
};