#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <utility>
#include <vector>

using namespace std;

int add_no_arithm(int a, int b);
int sub_no_arithm(int a, int b);
int sub_no_arithm2(int a, int b);
int mul_no_arithm(int a, int b);
int div_no_arithm(int a, int b);
int mod_no_arithm(int a, int b);

int main(int args, char *argv[])
{
    const int a = 3, b = 7;

    cout << a << " + " << b << " = "
         << add_no_arithm(a, b) << endl
         << a << " - " << b << " = "
         << sub_no_arithm(a, b) << endl
         << a << " - " << b << " = "
         << sub_no_arithm2(a, b) << endl
         << a << " * " << b << " = "
         << mul_no_arithm(a, b) << endl
         << a << " / " << b << " = "
         << div_no_arithm(a, b) << endl
         << a << " % " << b << " = "
         << mod_no_arithm(a, b) << endl;

    return 0;
}

int add_no_arithm(int a, int b)
{
    if (a & b)
        return add_no_arithm(a ^ b, (a & b) << 1);

    return a | b;
}

int sub_no_arithm(int a, int b)
{
    return add_no_arithm(a, add_no_arithm(~b, 0x1));
}

int sub_no_arithm2(int a, int b)
{
    int mono = 0x1;

    b = ~b;
    while (mono != 0)
    {
        int c = (b & mono) << 1;
        b ^= mono;
        mono = c;
    }
    while (b != 0)
    {
        int c = (a & b) << 1;
        a ^= b;
        b = c;
    }

    return a;
}

int mul_no_arithm(int a, int b)
{
    int result = 0;

    for (; a && b; a >>= 1, b <<= 1)
        if (a & 1)
            result = add_no_arithm(result, b);

    return result;
}

int div_no_arithm(int a, int b)
{
    int m = 1, q = 0;

    if (a < b)
        return 0;
    if (b == 0)
    {
        cerr << "0div err!" << endl;
        exit(EXIT_FAILURE);
    }

    while (b <= a)
    {
        b <<= 1;
        m <<= 1;
    }
    while (1 < m)
    {
        b >>= 1;
        m >>= 1;
        if (a >= b)
        {
            a -= b;
            q |= m;
        }
    }

    return q;
}

int mod_no_arithm(int a, int b)
{
    return sub_no_arithm(a, mul_no_arithm(b, div_no_arithm(a, b)));
}
