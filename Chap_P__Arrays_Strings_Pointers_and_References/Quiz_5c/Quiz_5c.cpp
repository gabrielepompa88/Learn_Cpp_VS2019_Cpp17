#include<iostream>
#include<array>

//void printArray(int y[])
void printArray(const std::array<int, 5> &y)
{
    for (int yi : y)
    {
        std::cout << yi << ' ';
    }
}

// overloaded function called when y is a standard array
void printArray(int (&y)[5]) {

    std::cout << "Calling overloaded printArray for standard arrays. \n";

    for (int yi : y)
    {
        std::cout << yi << ' ';
    }
}

int main()
{
    // using std::array
    std::array<int, 5> x{ 9, 7, 5, 3, 1 };
    printArray(x);

    std::cout << '\n';

    // using fixed arrays
    int z[]{ 9, 7, 5, 3, 1 };
    printArray(z);

    return 0;
}