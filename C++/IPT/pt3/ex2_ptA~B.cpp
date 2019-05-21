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

    int getMax()
    {
        int max = (a - b) >> 31;
        max = (((a & ~max) | (b & max)) - c) >> 31;
        return (a & ~max) | (c & max);
    }

    int getMin()
    {
        int max = (a - b) >> 31;
        max = (((a & max) | (b & ~max)) - c) >> 31;
        return (a & max) | (c & ~max);
    }

    int getSum()
    {
        return a + b + c;
    }
};

int main()
{
    TriComp triComp(12, 73, 77);

    cout << triComp.getMax() << endl;
    cout << triComp.getMin() << endl;
    cout << triComp.getSum() - triComp.getMax() - triComp.getMin() << endl;

    return 0;
}
