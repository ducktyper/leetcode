#include "helper.h"
#include "leetcode_029_divide_two_integers.c"

void printBinary(int num);
int reverseSign(int num);

int main()
{
    assertInt(5, divide(10, 2));
    assertInt(6, divide(302, 50));
    assertInt(-6, divide(302, -50));
    assertInt(2147483647, divide(-2147483648, -1));
    assertInt(-2147483648, divide(-2147483648, 1));
}

void printBinary(int num)
{
    int p = 1;
    char str[33];
    for (int i = 31; i >= 0; i--)
    {
        str[i] = num & p ? '1' : '0';
        p <<= 1;
    }
    str[32] = '\0';
    printf("%s\n", str);
}

int reverseSign(int num)
{
    int out = 0, p = 1;
    for(int i = 0; i < 32; i++)
    {
        if ((out && !(num & p)) || (!out && (num & p)))
            out |= p;
        p <<= 1;
    }
    return out;
}

