#include <iostream>

void swap(int& a, int& b) 
{
    std::cout << "Calling my own swap function." << "\n";

    int temp{ a };

    a = b;
    b = temp;

}


int main()
{
    std::cout << "x = ";
    int x{};
    std::cin >> x;

    int y{};
    do
    {
        std::cout << "y = ";
        std::cin >> y;
    } while (x == y); // keep asking untill a different value is typed

    std::cout << "x = " << x << "; y = " << y << "\n";

    swap(x, y);

    std::cout << "x = " << x << "; y = " << y << "\n";

    return 0;
}