#include <chrono>
#include <iostream>
#include <iterator>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

class TriComp
{
private:
    const int a, b, c;

public:
    TriComp(int u, int v, int w) : a(u), b(v), c(w) {}
    ~TriComp() {}

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
    TriComp triComp(12, 73, 77);

    cout << triComp.getMaxByElif() << endl;
    cout << triComp.getMaxByTernary() << endl;
    cout << triComp.getMaxBySAR() << endl;

    return 0;
}
