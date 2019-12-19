#include "constants.h"

#include "height.h"

#include <iostream>

int main()
{
    const double H = getTowerHeight();
    double ht = H;
    int t = 0;

    while (ht > 0.0) {
        ht = calculateAndPrintHeight(H, t);
        t += 1;
    }

    return 0;
}