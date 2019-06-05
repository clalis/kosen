#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <utility>
#include <vector>

using namespace std;

int rnd5();
int rnd7Const();
pair<int, int> rnd7Vari();
pair<int, int> rnd7Without();
int rnd15();

int main()
{
    pair<int, int> p1, p2;
    vector<int> v1, v2;

    for (size_t i = 0; i < 0x1000; i++)
    {
        p1 = rnd7Vari();
        p2 = rnd7Without();

        v1.push_back(p1.first);
        v2.push_back(p2.first);

        // cout << rnd7Const() << p1.second << p2.second << endl;
    }
    cout << "average1: " << accumulate(v1.begin(), v1.end(), 0) / static_cast<float>(v1.size()) << endl
         << "average2: " << accumulate(v2.begin(), v2.end(), 0) / static_cast<float>(v2.size()) << endl;

    for (size_t i = 0; i < 15; i++)
    {
        cout << rnd15() << endl;
    }

    return 0;
}

int rnd5()
{
    random_device rnd;
    mt19937_64 mt(rnd());
    uniform_int_distribution<> rand100(0, 4);

    return rand100(mt);
}

int rnd7Const() { return ((rnd5() + rnd5()) % 7 + 1); }

pair<int, int> rnd7Vari()
{
    int cnt = 0;

    while (true)
    {
        int num = 5 * rnd5() + rnd5();
        cnt++;
        if (num < 21)
            return make_pair(cnt * 2, num % 7 + 1);
    }
}

pair<int, int> rnd7Without()
{
    int cnt = 0;

    while (true)
    {
        int num = 2 * rnd5();
        int odd = rnd5();
        cnt++;
        if (odd != 4)
        {
            num += odd % 2;
            if (odd < 7)
                return make_pair(cnt * 2, num % 7 + 1);
        }
    }
}

int rnd15()
{
    while (true)
    {
        int num = 2 * rnd7Without().second;
        int odd = rnd7Without().second;
        if (odd != 7)
        {
            num += odd % 2;
            if (num < 14)
                return num + 1;
        }
    }
}
