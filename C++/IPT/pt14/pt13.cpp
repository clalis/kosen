//
// Created by s_cla on 2019/08/14.
//

#include "Pt13.h"

using namespace std;

unsigned Pt13::_n;
set<unsigned> Pt13::_set;

Pt13::Pt13(unsigned n) {
    cout << endl << "Starting \"Pt13\"..." << endl;
    set<unsigned> s;
    vector<unsigned> v(n);
    iota(v.begin(), v.end(), 0);
    for (const auto &item : v) s.insert(item);

    setSet(s);
    setN(n);
}

Pt13::~Pt13() = default;

unsigned Pt13::getN() {
    return _n;
}

void Pt13::setN(unsigned n) {
    _n = n;
}

const set<unsigned> &Pt13::getSet() {
    return _set;
}

void Pt13::setSet(const set<unsigned> &set) {
    _set = set;
}

unsigned Pt13::cnt2Rcr(unsigned n) {
    if (n == 0) return 0;

    unsigned power = 1;
    while ((10 * power) < n) power *= 10;
    unsigned first = n / power, remainder = n % power;

    unsigned nTwosFirst = 0;
    if (first > 2) nTwosFirst += power;
    else if (first == 2) nTwosFirst += remainder + 1;

    unsigned nTwosOther = first * Pt13::cnt2Rcr(power - 1) + Pt13::cnt2Rcr(remainder);
    cout << nTwosFirst + nTwosOther << endl;

    return nTwosFirst + nTwosOther;
}

void Pt13::cnt2Itr() {
    unsigned cnt2 = 0, digit = 0;
    unsigned num = getN(), seenDigits = 0, pos = 0, pow10Pos = 1;
    while (num > 0) {
        digit = num % 10;
        unsigned pow10PosDecr = pow10Pos / 10;
        cnt2 += digit * pos * pow10PosDecr;

        if (digit == 2) cnt2 += seenDigits + 1;
        else if (digit > 2) cnt2 += pow10Pos;

        seenDigits += pow10Pos * digit;
        pos++;
        pow10Pos *= 10;
        num /= 10;
    }
    cout << endl << cnt2 << endl;
}

void Pt13::cnt2Itr(unsigned key) {
    unsigned cnt2 = 0, digit = 0;
    unsigned num = getN(), seenDigits = 0, pos = 0, pow10Pos = 1;
    while (num > 0) {
        digit = num % 10;
        unsigned pow10PosDecr = pow10Pos / 10;
        cnt2 += digit * pos * pow10PosDecr;

        if (digit == key) cnt2 += seenDigits + 1;
        else if (digit > key) cnt2 += pow10Pos;

        seenDigits += pow10Pos * digit;
        pos++;
        pow10Pos *= 10;
        num /= 10;
    }
    cout << endl << cnt2 << endl;
}

/**
 * @fn
 * 0~nまでの数字で使われる文字を表示する
 * @brief Count number of characters
 * @param none
 * @return void
 * @sa getDigit(unsigned n)
 * @detail 0はlog10()で-infなのでcntに+1
 */
void Pt13::getDigit() {
    unsigned cnt = 0;

    for (const auto &item : getSet()) cnt += getDigit(item);
    cout << endl << "Counts: " << (cnt + 1) << endl;
}

void Pt13::getSum(unsigned key) {
    vector<unsigned> dump(0);

    for (const auto &item : _set) if (to_string(item).find(to_string(key)) != string::npos) dump.push_back(item);
    cout << "SUM: " << reduce(dump.begin(), dump.end()) << endl;
}

void Pt13::getProd(unsigned key) {
    vector<unsigned> dump(0);

    for (const auto &item : _set) if (to_string(item).find(to_string(key)) != string::npos) dump.push_back(item);
    cout << "SUM: " << reduce(dump.begin(), dump.end(), 1ULL, multiplies<unsigned long long>()) << endl;
}
