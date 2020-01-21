
#include "constants.h"

#include "height.h"

#include <iostream>

// gets height of the tower (H) from user and returns it
double getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: H = ";
    double H;
    std::cin >> H;
    return H;
}

// Returns height from ground (ht) after "t" seconds
double calculateHeight(double h0, int t)
{
    // Using formula: [ s(t) = v * t + (g * t^2) / 2 ], here "v" (initial velocity) = 0
    double st = (myConst::g * (t * t)) / 2;
    double ht = h0 - st;

    return ht;
}

// Prints height (ht) every second (t) till ball has reached the ground
void printHeight(double ht, int t)
{
    if (ht > 0.0)
        std::cout << "At t = " << t << " seconds, the ball is at height: h(" << t << ") = " << ht << " meters\n";
    else
        std::cout << "At t = " << t << " seconds, the ball is on the ground.\n";
}

double calculateAndPrintHeight(double H, int t)
{
    double ht = calculateHeight(H, t);
    printHeight(ht, t);

    return ht;

}
