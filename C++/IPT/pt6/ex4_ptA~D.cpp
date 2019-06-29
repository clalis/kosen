#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <utility>
#include <vector>

using namespace std;

int getMaxSum(vector<int> ary, size_t len);
int getMaxProduct(vector<int> ary, size_t len);
int getFixedMaxProduct(vector<int> ary, size_t len);

int main()
{
    vector<int> v1{2, -8, 3, -2, 4, -10};
    vector<int> v2{-2, 0, 3, 0, -8, 0, 10};
    vector<int> v3{2, -9, 3, 1, -10, -15, 10};

    cout << "INPUT1: ";
    for (auto &&i : v1)
        cout << i << " ";
    cout << "\nINPUT2: ";
    for (auto &&i : v2)
        cout << i << " ";
    cout << "\nINPUT3, INPUT4: ";
    for (auto &&i : v3)
        cout << i << " ";
    cout << endl
         << "OUTPUT1: " << getMaxSum(v1, v1.size()) << endl
         << "OUTPUT2: " << getMaxProduct(v2, v2.size()) << endl
         << "OUTPUT3: " << getMaxProduct(v3, v3.size()) << endl
         << "OUTPUT4: " << getFixedMaxProduct(v3, v3.size()) << endl;

    return 0;
}

int getMaxSum(vector<int> ary, size_t len)
{
    int maxfar = 0, maxend = 0;

    for (size_t i = 0; i < len; i++)
    {
        maxend = max(0, maxend + ary.at(i));
        maxfar = max(maxfar, maxend);
    }

    return maxfar;
}

int getMaxProduct(vector<int> ary, size_t len)
{
    int maxprod = 0, prod = 1;

    for (size_t i = 0; i < len; i++)
    {
        if (ary.at(i) == 0)
            prod = 1;
        else
        {
            prod *= ary.at(i);
            if (maxprod < prod)
                maxprod = prod;
            else if (maxprod < ary.at(i))
                maxprod = ary.at(i);
        }
    }

    return maxprod;
}

int getFixedMaxProduct(vector<int> ary, size_t len)
{
    int maxprod = 0, prod = 1;

    for (size_t h = 0; h < len; h++)
    {
        prod = 1;
        for (size_t i = h; i < len; i++)
        {
            if (ary.at(i) == 0)
                prod = 1;
            else
            {
                prod *= ary.at(i);
                if (maxprod < prod)
                    maxprod = prod;
                else if (maxprod < ary.at(i))
                    maxprod = ary.at(i);
            }
        }
    }

    return maxprod;
}