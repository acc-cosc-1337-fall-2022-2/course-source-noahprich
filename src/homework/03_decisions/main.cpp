//write include statements

#include <iostream>
#include <string>
#include "decisions.h"

using std::cout;
using std::cin;

int main() 
{
	
	cout<<"Main Menu"<<"/n"
		<<"1 - Letter grade using if"
		<<"2 - Letter grade using switch"
		<<"3 - Exit";
	cin>>int choice;

	if (choice == 1)
	{
		get_letter_grade_using_if(int grade);
	}

	else if (choice == 2)
	{
		get_letter_grade_using_switch(int grade);
	}

	else
	{
		cout<<"Goodbye"<<"/n";
	}

	return 0;
}