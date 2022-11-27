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
    for(int i=0; i<pegs.size();i++)
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
 return false;
}

bool TicTacToe::check_row_win()
{
  return false;
}
bool TicTacToe::check_diagonal_win()
{
return false;
}

void TicTacToe::set_winner()
{
  if (player=="X")
    winner="O";
  else 
  winner ="X";
}
std::ostream& operator<<(std::ostream& out, const TicTacToe &game)
{
  //...display board overload..................................................
  if (game.pegs.size()==9)
  {
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
  }
  else
  {
      for(int i=0; i<16; i++)
    {   
      if (i==4||i==8||i==12)
           {
             std::cout<<"\n";
           }
      std::cout<<game.pegs[i];
      if(i!=3&&i!=7&&i!=11&&i!=15)
          std::cout<<"|";
    }
  }
  
  return out;
}
std::istream& operator>>(std::istream& in, TicTacToe& game)
    {
    Position_Loop:int position;//will loop to here for bad input.
    if (game.pegs.size()==9)
    {
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
    }
    else
    { 
    std::cout<<"\n What position do you wish to play? Choose 1-16:\t";
		std::cin>>position;
		std::cin.clear();
		std::cin.sync();
      if (position!=1 && position!=2 && position!=3 && position!=4 && position!=5 && position!=6 && position!=7 && position!=8 && position!=9&& position!=10 && position!=11 && position!=12 && position!=13 && position!=14 && position!=15 && position!=16)
		{
      			std::cout<<"\nPlease enter a single digit number between 1 & 16 to play\n";
			goto Position_Loop;
		}
	if ((game.pegs[(position-1)])=="X"||(game.pegs[(position-1)]=="O"))
					{
						std::cout<<"You can't play that position-- someone already did.";
						goto Position_Loop;
					}
		//move has passed validation. add to board moves.
		game.mark_board(position);
    }
    

      return in;
    }