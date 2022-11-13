//cpp
#include "tic_tac_toe.h"
#include <iostream>
#include <iomanip>
void TicTacToe::start_game(string first_player)
{
if (first_player=="X"||first_player=="O")
   {
        TicTacToe::player= first_player;
        TicTacToe::clear_board(); 
   } 
}

void TicTacToe::mark_board(int position)
{
    pegs[position-1]=player;
    TicTacToe::set_next_player();
}
string TicTacToe::get_player()const
{
    return TicTacToe::player;
}

  void TicTacToe::set_next_player()
  {
    if(TicTacToe::player=="X")
        TicTacToe::player="O";
    else
    player="X";
  }

  bool TicTacToe::check_board_full()
  {
    bool space_checker=true;
    for(int i=0; i<9;i++)
            if(TicTacToe::pegs[i]==" ")
                space_checker=false;
    return space_checker;
  }
   void TicTacToe::clear_board()
   {
        for(int i=0; i<9;i++)
                (TicTacToe::pegs[i])=" ";
   }

  bool TicTacToe::game_over()
  {
    bool return_value;
    if ( check_column_win()==true|| check_row_win()==true||check_diagonal_win()==true)
      {
        set_winner();
        return_value= true;
      }
  else if(check_board_full()==true)
   {
      winner="C";
      return_value= true;
   }
   else if (check_board_full()!=true)
    return_value= false;
  return return_value;
  }
string TicTacToe::get_winner()
{
return winner;
}
bool TicTacToe::check_column_win()
{
  bool return_value=false;
  if((pegs[0]=="X"&&pegs[3]=="X"&&pegs[6]=="X")||(pegs[0]=="O"&&pegs[3]=="O"&&pegs[6]=="O"))
    return_value= true;
  else if((pegs[1]=="X"&&pegs[4]=="X"&&pegs[7]=="X")||(pegs[1]=="O"&&pegs[4]=="O"&&pegs[7]=="O"))
    return_value= true;
  else if((pegs[2]=="X"&&pegs[5]=="X"&&pegs[8]=="X")||(pegs[2]=="O"&&pegs[5]=="O"&&pegs[8]=="O"))
    return_value= true;
  return return_value;
}

bool TicTacToe::check_row_win()
{
  bool return_value=false;
  if((pegs[0]=="X"&&pegs[1]=="X"&&pegs[2]=="X")||(pegs[0]=="O"&&pegs[1]=="O"&&pegs[2]=="O"))
    return_value= true;
  else if((pegs[3]=="X"&&pegs[4]=="X"&&pegs[5]=="X")||(pegs[3]=="O"&&pegs[4]=="O"&&pegs[5]=="O"))
    return_value= true;
  else if((pegs[6]=="X"&&pegs[7]=="X"&&pegs[8]=="X")||(pegs[6]=="O"&&pegs[7]=="O"&&pegs[8]=="O"))
    return_value= true;
  return return_value;
}
bool TicTacToe::check_diagonal_win()
{
  bool return_value=false;
  if((pegs[0]=="X"&&pegs[4]=="X"&&pegs[8]=="X")||(pegs[0]=="O"&&pegs[4]=="O"&&pegs[8]=="O"))
    return_value= true;
  else if((pegs[6]=="X"&&pegs[4]=="X"&&pegs[2]=="X")||(pegs[6]=="O"&&pegs[4]=="O"&&pegs[2]=="O"))
    return_value= true;
  return return_value;
}

void TicTacToe::set_winner()
{
  if (player=="X")
    winner="O";
  else 
  winner ="X";
}
std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
  //...display board overload..................................................
      for(int i=0; i<9; i++)
    {   
      if (i==3||i==6)
           {
             std::cout<<"\n";
           }
      std::cout<<game.pegs[i];
      if(i!=2&&i!=5&&i!=8)
          std::cout<<"|";
    }
  return out;
}
std::istream& operator>>(std::istream& in, TicTacToe& game)
    {
    Position_Loop:int position;//will loop to here for bad input.
    std::cout<<"\n What position do you wish to play? Choose 1-9:\t";
		std::cin>>position;
		std::cin.clear();
		std::cin.sync();
		//input validation: if input not in proper range get new input.
		if (position!=1 && position!=2 && position!=3 && position!=4 && position!=5 && position!=6 && position!=7 && position!=8 && position!=9)
		{
			std::cout<<"\nPlease enter a single digit number between 1 & 9 to play\n";
			goto Position_Loop;
		}
	if ((game.pegs[(position-1)])=="X"||(game.pegs[(position-1)]=="O"))
					{
						std::cout<<"You can't play that position-- someone already did.";
						goto Position_Loop;
					}
		//move has passed validation. add to board moves.
		game.mark_board(position);

      return in;
    }