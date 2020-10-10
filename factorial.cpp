//factorial
//Jiahong, Ma

#include <iostream>
#include <cmath>

const int EXT = 5;

int length(int n)
{
    double m = 0;
    for (int i = 1; i <= n; ++i)
    {
        m += log(i);
    }
    return int(m + 1);
}

void fact(int n)
{
    //------n<=0---------
    if (n < 0)
    {
        std::cout << "error\n";
        return;
    }
    else if (0 == n)
    {
        std::cout << 1;
        return;
    }

    //---------construct--------------
    int len = length(n) + EXT;
    short *num = new short[len];
    short carry, sum;

    //----------init-------------
    for (int i = 0; i < len; ++i)
    {
        num[i] = 0;
    }
    num[0] = 1;

    //---------calc---------
    for (int i = 2; i <= n; ++i)
    {
        carry = 0;
        for (int j = 0; j < len; ++j)
        {
            sum = num[j] * i + carry;
            num[j] = sum % 10;
            carry = sum / 10;
        }
    }
    //-----------end------------

    //-----------output----------
    bool zero = true;
    for (int i = len - 1; i >= 0; --i)
    {
        if (zero)
        {
            if (0 != num[i - 1])
            {
                zero = false;
            }
        }
        else
        {
            std::cout << num[i];
        }
    }

    //-----------destruct-----------
    delete[] num;
}

int main()
{
    fact(1000);
    return 0;
}
