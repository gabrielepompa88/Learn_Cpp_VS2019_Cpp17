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

int main()
{
    //int x[]{ 9, 7, 5, 3, 1 };
    std::array<int, 5> x{ 9, 7, 5, 3, 1 };

    printArray(x);

    std::cout << '\n';

    return 0;
}