#include <iostream>
#include <array>
#include <typeinfo>

int main()
{
    // std::array<int, 5> myArray{ 7, 3, 1, 9, 5 };
    std::array myArray{ 7, 3, 1, 9, 5 };

    std::cout << typeid(myArray.size()).name() << '\n';

    // works in all the three ways
    using index_t = int;
    //using index_t = std::array<int, 5>::size_type;
    //using index_t = std::size_t;

    // Iterate through the array and print the value of the elements
    for (index_t i{ 0 }; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ' << typeid(i).name() << '\n';

    std::cout << '\n';

    return 0;
}