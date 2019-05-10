#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;

int main()
{
    const int N = 0x1000 * 0x1000;
    std::vector<int> v;

    auto start = system_clock::now();   // 計測スタート時刻を保存

    for (size_t i = 0; i < N; ++i)
        v.push_back(i);

    auto end = system_clock::now();     // 計測終了時刻を保存
    auto dur = end - start;             // 要した時間を計算
    auto msec = duration_cast<milliseconds>(dur).count();

    // 要した時間をミリ秒（1/1000秒）に変換して表示
    std::cout << msec << " milli sec \n";

    return 0;
}
