//write include statements

#include <iostream>
#include "data_types.h"

//write namespace using statement for cout

using std::cout;
/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	int num1, num2;
    cout << "Enter 1st number: ";
	cin >> num1;
	cout << "Enter 2nd number: ";
	cin >> num2;

	int result = num1 * num2;

	cout << "The result is: " << result;
}
