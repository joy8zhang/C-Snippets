#include <iostream>
#include "DivObserver.h"

int main() {
    Subject subj;
    DivObserver divObs1(&subj, 4);
    DivObserver divObs2(&subj, 3);
    subj.set_val(14);
}