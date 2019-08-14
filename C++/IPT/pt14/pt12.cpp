//
// Created by s_cla on 2019/08/12.
//

#include "Pt12.h"

using namespace std;

unsigned Pt12::_m;
unsigned Pt12::_n;
multiset<unsigned> Pt12::subset;

Pt12::Pt12() : Pt12(10, 10) {}

Pt12::Pt12(unsigned m, unsigned n) {
    cout << endl << "Starting \"Pt12\"..." << endl;
    setM(m);
    setN(n);
}

Pt12::~Pt12() = default;

void Pt12::pickEase() {
    subset.clear();
    for (size_t i = 0; i < _m; i++) subset.insert(getRnd());
    for (const auto &item : subset) cout << item << " ";
    cout << endl;
}

void Pt12::pickHard() {
    subset.clear();
    subset.insert(getRnd());
    while (subset.size() < _m) {
        unsigned picked = getRnd();
        for (const auto &item : subset) cout << item << " ";
        cout << ": " << picked << endl;
        if ((subset.find(picked) == subset.end())) subset.insert(picked);
    }
    for (const auto &item : subset) cout << item << " ";
    cout << endl;
}

unsigned Pt12::getRnd() {
    random_device device;
    mt19937_64 mt1993764(device());
    uniform_int_distribution<> dist(0, _n - 1);

    return static_cast<unsigned>(dist(mt1993764));
}
