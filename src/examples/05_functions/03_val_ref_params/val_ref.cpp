void val_ref_params(int num, int& num1)
{
    num = 20;
    num1 = 30;
}

void const_ref_param(const int& num )
{
    //num = 50; can't modify value
}