#include<iostream>
#include "if.h"//to use is_even function here

using std::cout;
using std::cin;

int main() 
{
	//create a bool variable named even
	//create an int variable named value
	auto over_time = false;
	auto hours = 0;

	//prompt user for a keyboard number
	//assign the number to the value variable
	cout <<"Enter hours: ";
	cin >> hours;

	//call the is_even function with value as its argument
	//and assign its return value to the even variable
	over_time = is_overtime(hours);


	//display even if number is even
	if(over_time)
	{
		cout<<"Hours: "<<hours<<" is overtime\n";
	}

	return 0;
}
