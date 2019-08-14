#include "Pt12.h"
#include "Pt13.h"


int main() {
    Pt12 pt12;

    Pt12::pickEase();
    Pt12::pickHard();

    Pt13 pt13;

    Pt13::cnt2Rcr();
    Pt13::cnt2Itr();
    Pt13::cnt2Itr(7);
    Pt13::getDigit();
    Pt13::getSum();
    Pt13::getProd();

    return 0;
}
