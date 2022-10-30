//cpp

#include "tic_tac_toe.h"

bool TicTacToe::game_over() {
    return check_board_full();
}

void TicTacToe::start_game(string first_player) {
    bool check = false;
    while (!check) {
        if (first_player == "X" || first_player == "O") {
            player = first_player;
            check = true;
        }
        else {
            cout << "Invalid entry. Please enter 'X' or 'O'\n"
                    "Do you wish to play 'X' or 'O'?\n";
            cin >> (first_player);
        }
    }
    clear_board();
}

void TicTacToe::mark_board(int position) {
    while (!check_section(position)) {
        cout << "Invalid entry. Please select a position"
                " that is not already taken.\n";
        cin >> position;
        position--;
    }
//    i subtracted position by 1 in main because keeping track of that in all
//    the other functions is too stressful
    pegs[position] = player;
    choices[position] = ' ';
    set_next_player();
}

bool TicTacToe::check_section(int position) {
    if (pegs[position] != " ") return false;
    else return true;
}

string TicTacToe::get_player() const {
    return player;
}

void TicTacToe::display_board() const {
    cout << "Available placements left:"
         << "\n " << choices[0] << " | " << choices[1] << " | " << choices[2]
         << "\n " << choices[3] << " | " << choices[4] << " | " << choices[5]
         << "\n " << choices[6] << " | " << choices[7] << " | " << choices[8] << "\n";
    cout << "Current board:"
         << "\n " << pegs[0] << " | " << pegs[1] << " | " << pegs[2]
         << "\n " << pegs[3] << " | " << pegs[4] << " | " << pegs[5]
         << "\n " << pegs[6] << " | " << pegs[7] << " | " << pegs[8] << "\n"
         << "Make your choice: ";
}

void TicTacToe::set_next_player() {
    if (player == "X") player = "O";
    else player = "X";
    cout << "Next player! Now playing " << player << ".\n";
}

bool TicTacToe::check_board_full() {
    for (int i = 0; i<9; i++) {
        if (pegs[i] == " ") return false;
    }
    return true;
}

void TicTacToe::clear_board() {
    for (int i = 0; i<9; i++) {
        pegs[i] = " ";
    }
    choices = "123456789";
}