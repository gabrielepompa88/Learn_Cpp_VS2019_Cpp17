#include "constants.h"

#include "height.h"

#include <iostream>

int main()
{
    const double H = getTowerHeight(); // height of the tower
    double ht = H; // height at time t (at t==0 is H, the height of the tower)
    int t = 0; // time 

    while (ht > 0.0) {
        ht = calculateAndPrintHeight(H, t);
        t += 1;
    }

    return 0;
}