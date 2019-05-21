#include <chrono>
#include <iostream>
#include <iterator>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

class Comp
{
private:
    const int a, b;

public:
    Comp(int m, int n) : a(m), b(n) {}
    ~Comp() {}

    int getMaxByElif()
    {
        int max;

        if (a >= b)
            max = a;
        else
            max = b;

        return max;
    }

    int getMaxByTernary() { return ((a >= b) ? a : b); }

    int getMaxBySAR() // SAR : Shift Arithmetic Right
    {
        int max = (a - b) >> 31;
        return (a & ~max) | (b & max);
    }
};

int main()
{
    Comp comp(12, 77);

    cout << comp.getMaxByElif() << endl;
    cout << comp.getMaxByTernary() << endl;
    cout << comp.getMaxBySAR() << endl;

    return 0;
}
