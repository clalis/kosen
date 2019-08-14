//
// Created by s_cla on 2019/08/12.
//

#ifndef PT14_PT12_H
#define PT14_PT12_H


#include <iostream>
#include <iterator>
#include <random>
#include <set>
#include <utility>

class Pt12 {
public:
    Pt12();

    Pt12(unsigned m, unsigned int n);

    virtual ~Pt12();

    static void pickEase();

    static void pickHard();

    static unsigned getM() { return _m; }

    static unsigned getN() { return _n; }

    static void setM(unsigned m) { _m = m; }

    static void setN(unsigned n) { _n = n; }

private:
    static unsigned _m, _n;
    static std::multiset<unsigned> subset;

    static unsigned getRnd();
};


#endif //PT14_PT12_H
