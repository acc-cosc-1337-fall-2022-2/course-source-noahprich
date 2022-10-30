//write include statements
#include "if_else.h"
#include<iostream>

//write cin and cout using statements
using std::cout;
using std::cin;

/*
Write code to capture year from keyboard.
Pass the year to get_generation function and display function result.
*/
int main() 
{
	auto num = 0;
	cout<<"Enter a number ";
	cin>>num;

	auto result = is_even(num);

	if(result == true)
	{
		cout<<"Number "<<num<<" is even\n";
	}
	else
	{
		cout<<"Number "<<num<<" is odd\n";
	}
	
	return 0;
}