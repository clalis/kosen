//
// Created by s_cla on 2019/08/14.
//

#ifndef PT14_PT13_H
#define PT14_PT13_H


#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <set>
#include <string>
#include <utility>
#include <vector>

class Pt13 {
public:
    Pt13() : Pt13(100) {}

    explicit Pt13(unsigned n);

    virtual ~Pt13();

    static unsigned getN();

    static void setN(unsigned n);

    static const std::set<unsigned int> &getSet();

    static void setSet(const std::set<unsigned int> &set);

    static unsigned cnt2Rcr(unsigned n = _n);

    static void cnt2Itr();

    static void cnt2Itr(unsigned key);

    static void getDigit();

    static unsigned getDigit(unsigned n) { return static_cast<unsigned>(log10(n) + 1); }

    static void getSum(unsigned key = 2);

    static void getProd(unsigned key = 2);

private:
    static unsigned _n;
    static std::set<unsigned> _set;
};


#endif //PT14_PT13_H
