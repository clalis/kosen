#include <chrono>
#include <iostream>
#include <iterator>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> arr(4);
    int a, b;

    for (size_t i = 0; i < 0x100000; i++)
    {
        a = 12, b = 36;

        // pt.1
        // cout << a << ", " << b << endl;

        auto start = chrono::system_clock::now(); // 計測スタート時刻を保存

        int tmp = a;
        a = b;
        b = tmp;

        auto end = chrono::system_clock::now(); // 計測終了時刻を保存

        // cout << a << ", " << b << endl;

        auto dur = end - start; // 要した時間を計算
        auto nsec = chrono::duration_cast<chrono::nanoseconds>(dur).count();

        // cout << "pt.1 : " << nsec << " nano sec" << endl; // 要した時間をナノ秒(1/10^-9)に変換して表示
        arr.at(0).push_back(nsec);

        // pt.2
        swap(a, b);
        // cout << a << ", " << b << endl;

        start = chrono::system_clock::now(); // 計測スタート時刻を保存

        a += b;
        b = a - b;
        a -= b;

        end = chrono::system_clock::now(); // 計測終了時刻を保存

        // cout << a << ", " << b << endl;
        dur = end - start; // 要した時間を計算
        nsec = chrono::duration_cast<chrono::nanoseconds>(dur).count();

        // cout << "pt.2 : " << nsec << " nano sec" << endl; // 要した時間をナノ秒(1/10^-9)に変換して表示
        arr.at(1).push_back(nsec);

        // pt.3
        swap(a, b);
        // cout << a << ", " << b << endl;

        start = chrono::system_clock::now(); // 計測スタート時刻を保存

        a ^= b;
        b = a ^ b;
        a ^= b;

        end = chrono::system_clock::now(); // 計測終了時刻を保存

        // cout << a << ", " << b << endl;
        dur = end - start; // 要した時間を計算
        nsec = chrono::duration_cast<chrono::nanoseconds>(dur).count();

        // cout << "pt.3 : " << nsec << " nano sec" << endl; // 要した時間をナノ秒(1/10^-9)に変換して表示
        arr.at(2).push_back(nsec);

        // pt.4
        swap(a, b);
        // cout << a << ", " << b << endl;

        start = chrono::system_clock::now(); // 計測スタート時刻を保存

        swap(a, b);

        end = chrono::system_clock::now(); // 計測終了時刻を保存

        // cout << a << ", " << b << endl;
        dur = end - start; // 要した時間を計算
        nsec = chrono::duration_cast<chrono::nanoseconds>(dur).count();

        // cout << "pt.4 : " << nsec << " nano sec" << endl; // 要した時間をナノ秒(1/10^-9)に変換して表示
        arr.at(3).push_back(nsec);
    }

    for (auto &&i : arr)
    {
        i.erase(i.begin());
        cout << accumulate(i.begin(), i.end(), 0) / i.size() << endl;
    }

    return 0;
}
