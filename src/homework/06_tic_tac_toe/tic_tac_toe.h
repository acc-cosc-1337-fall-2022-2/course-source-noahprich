//h
#include <string>
#include <vector>
using std::string;
using std::vector; 
#ifndef TICTACTOE_H
#define TICTACTOE_H
class TicTacToe
{   
   
 public:
   TicTacToe(){}
   TicTacToe(std::vector<string>p,string win){pegs=p;winner=win;}
   TicTacToe(int size):pegs(size*size," "){}
   friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
   friend std::istream& operator>>(std::istream& in, TicTacToe& game);
   bool game_over();
   void start_game(string first_player);
   void mark_board(int position);
   string get_player()const;
   string get_winner();
   void set_winner();//don't know why, uml said this should be public
  vector<string> get_pegs()const{return pegs;}
 
 protected:
   vector<string> pegs;
   virtual bool check_column_win();
   virtual bool check_row_win();
   virtual bool check_diagonal_win();
   
 private:   
   void set_next_player();
   bool check_board_full();
   void clear_board();
   std::string player; 
  
   string winner;
};
#endif