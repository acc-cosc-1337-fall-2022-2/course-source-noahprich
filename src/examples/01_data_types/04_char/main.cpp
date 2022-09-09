#include "char.h"
#include<iostream>

using std::cout;

int main()
{
    char letter = 'A';
    int ascii = get_char_ascii_value(letter);

    cout<<"ASCII value for "<<letter<<" is "<<ascii<<"\n";
    
    return 0;
}