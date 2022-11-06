//cpp
#include "tic_tac_toe.h"

bool TicTacToe::game_over() {
    if (check_column_win() || check_row_win() ||
        check_diagonal_win()) {
        set_winner();
        return true;
    }
    else if (check_board_full()) {
        winner = "C";
        return true;
    }
    else return false;
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
            "Now playing " << player << ".\nMake your choice: ";
}

void TicTacToe::set_winner() {
    if(player == "X") winner = "O";
    else winner = "X";
}

void TicTacToe::set_next_player() {
    if (player == "X") player = "O";
    else player = "X";
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

string TicTacToe::get_winner() {
    return winner;
}

bool TicTacToe::check_column_win() {
    if (pegs[0]+pegs[3]+pegs[6] ==  "XXX" || pegs[0]+pegs[3]+pegs[6] == "OOO") return true;
    else if (pegs[1]+pegs[4]+pegs[7] ==  "XXX" || pegs[1]+pegs[4]+pegs[7] == "OOO") return true;
    else if (pegs[2]+pegs[5]+pegs[8] == "XXX" || pegs[2]+pegs[5]+pegs[8] == "OOO") return true;
    else return false;
}

bool TicTacToe::check_row_win() {
    if (pegs[0]+pegs[1]+pegs[2] == "XXX" || pegs[0]+pegs[1]+pegs[2] == "OOO") return true;
    else if (pegs[3]+pegs[4]+pegs[5] == "XXX" || pegs[3]+pegs[4]+pegs[5] == "OOO") return true;
    else if (pegs[6]+pegs[7]+pegs[8] == "XXX" || pegs[6]+pegs[7]+pegs[8] == "OOO") return true;
    else return false;
}

bool TicTacToe::check_diagonal_win() {
    if (pegs[0]+pegs[4]+pegs[8] == "XXX" || pegs[0]+pegs[4]+pegs[8] == "OOO") return true;
    else if (pegs[2]+pegs[4]+pegs[6] == "XXX" || pegs[2]+pegs[4]+pegs[6] == "OOO") return true;
    else return false;
}