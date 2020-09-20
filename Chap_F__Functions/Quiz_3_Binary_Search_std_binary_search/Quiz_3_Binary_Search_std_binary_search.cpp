#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

    std::vector<int> array{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    // We're going to test a bunch of values to see if they produce the expected results
    constexpr int numTestValues{ 9 };
    // Here are the test values
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // And here are the expected results for each value
    int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    // Loop through all of the test values
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // See if our test value is in the array (or not)
        int found{ std::binary_search(array.begin(), array.end(), testValues[count]) };

        // index initialized to -1 (that is, not found default value)
        int index{ -1 };

        if (found)
        {
            // p is a std::pair of iterators, the first (p.first) pointing to the first element found
            // matching testValues[count]. And the last (p.second) pointing to the last one.
            auto p{ std::equal_range(array.begin(), array.end(), testValues[count]) };

            // index of element found is calculated as distance between the iterator to the beginning of the array
            // and the iterator to the first element found
            index = std::distance(array.begin(), p.first);
        }

        // If it matches our expected value, then great!
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}