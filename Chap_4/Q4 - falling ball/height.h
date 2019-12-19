#ifndef HEIGHT_H
#define HEIGHT_H

// gets height of the tower (H) from user and returns it
double getTowerHeight();

// Returns height from ground (ht) after "t" seconds
double calculateHeight(double h0, int t);

// Prints height (ht) every second (t) till ball has reached the ground
void printHeight(double ht, int t);

double calculateAndPrintHeight(double H, int t);

#endif