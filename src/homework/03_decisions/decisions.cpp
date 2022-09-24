//write include statement for decisions header
#include <iostream>
#include <string>
#include "decisions.h"

using std::cout;
using std::cin;
using std::string;

//Write code for function(s) code here
std::string get_letter_grade_using_if (int grade)
{
    if (grade >= 90){
        cout<<"Your grade: A "<<grade<<"/n";
    }
    else if (grade >=80){
        cout<<"Your grade: B "<<grade<<"/n";
    }
    else if (grade >=70){
        cout<<"Your grade: B "<<grade<<"/n";
    }
    else if (grade >=60){
        cout<<"Your grade: B "<<grade<<"/n";
    }
    else if (grade <= 59){
        cout<<"Your grade: F "<<grade<<"/n";
    }
    else {
        cout<<"That is not a valid grade input. Try again..."<<"/n";
    }
    return 0;
}

std::string get_letter_grade_using_switch (int grade)
{
    switch (grade) 
    {
        case 
    }

    return 0;
}
