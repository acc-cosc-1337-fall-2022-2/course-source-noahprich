//write include statements

#include <iostream>
#include <string>
#include "decisions.h"

using std::cout;
using std::cin;
using std::string;

int main() 
{
	string letter_grade;
	int option;
	int grade;

	cout<<"Main Menu"<<"\n"
		<<"1 - Letter grade using if" << "\n"
		<<"2 - Letter grade using switch" << "\n"
		<<"3 - Exit" << "\n";
	cin>>option;

switch(option){

	case 1:
	cout << "Enter a grade: ";
	cin >> grade;
	letter_grade = get_letter_grade_using_if(grade);

	if (grade > 0 && grade <= 100) {
		letter_grade = get_letter_grade_using_switch(grade);
		cout <<  letter_grade << "\n";
	}
	else {
		cout << "Number out of range" << "\n";
	}
	
	break;

	case 2:
	cout << "Enter a grade: ";
	cin >> grade;
	
	if (grade > 0 && grade <= 100) {
		letter_grade = get_letter_grade_using_switch(grade);
		cout <<  letter_grade << "\n";
	}
	else {
		cout << "Number out of range" << "\n";
	}

	break;

	}

	return 0;
}