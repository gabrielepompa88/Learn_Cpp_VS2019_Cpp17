/* ORIGINAL CODE SNIPPET (wrong)

int* allocateArray(const int length)
{
    int temp[length]{};
    return temp;
}

ERROR: length is not a compile-time variable, moreover variable temp goes out-of-scope,
therefore the returned pointer would be pointing to deallocated memory.

Solution:

- use std::array
*/

#include <iostream>
#include <vector>

/* ALTERNATIVE 1: using dynamic memory allocation

int* allocateArray(const int length)
{
    int *temp = new int[length] {10, 20, 30};

    return temp;

}
*/

std::vector<int> allocateArray(const int length){

    std::vector<int> temp(length);

    for (int i{ 0 }; i < length; ++i) {
        temp[i] = 10*(i+1);

    }

    return temp;
}
int main()
{

    int L{3};

    // if using ALTERNATIVE 1
    // int *arr{};

    // if using ALTERNATIVE 2
    std::vector<int> arr{};

    arr = allocateArray(L);

    for (int i{ 0 }; i < L; ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << "\n";

    }

    // if using ALTERNATIVE 1
    // delete[] arr;

    return 0;
}