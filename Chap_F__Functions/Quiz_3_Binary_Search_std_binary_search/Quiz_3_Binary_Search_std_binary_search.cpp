#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

enum class Status {

    BELOW_RANGE,
    IN_RANGE_NOT_FOUND,
    FOUND,
    ABOVE_RANGE
};

std::string printStatus(Status search_status) {
    switch (search_status)
    {
    case Status::BELOW_RANGE:
        return "below range of array";
        break;
    case Status::IN_RANGE_NOT_FOUND:
        return "not found (but in range of array)";
        break;
    case Status::FOUND:
        return "found";
        break;
    case Status::ABOVE_RANGE:
        return "above range of array";
        break;
    default:
        return "status unknown...";
        break;
    }
}
int main()
{

    // notice that array contains value '44' repeated 3 times and 46 repeated twice. 
    // If we look for 44, we expect p.first to point to its first occurrence, that is index 13;
    // If we look for 46 we expect p.first to point to its first occurrence, that is index 16;
    std::vector<int> array{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 44, 44, 46, 46, 48 };

    // We're going to test a bunch of values to see if they produce the expected results
    constexpr int numTestValues{ 10 };
    // Here are the test values. 
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 46, 49 };
    // And here are the expected results for each value. We use the convention :
    // -3 if BELOW_RANGE
    // -2 if IN_RANGE_NOT_FOUND
    // -1 if ABOVE_RANGE
    // the index of the first occurrence of the test value in array, otherwise
    int expectedValues[numTestValues]{ -3, 0, 3, -2, -2, 8, -2, 13, 16, -1 };

    // index of the element returned
    int index{};

    // status of search
    Status s;

    // Loop through all of the test values
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // p is a std::pair of iterators, the first (p.first) pointing to the first element found
        // matching testValues[count]. And the last (p.second) pointing to the last one.
        auto p{ std::equal_range(array.begin(), array.end(), testValues[count]) };

        if (p.first == p.second) { 
            
            // testValues[count] not found case(s) 

            if (p.first == array.begin()) {

                // case testValues[count] below each value in array
                s = Status::BELOW_RANGE;

                // index conventionally set to -3
                index = -3;
            }
            else if (p.first == array.end()) {

                // case testValues[count] above each value in array
                s = Status::ABOVE_RANGE;

                // index conventionally set to -1
                index = -1;
            }
            else {

                // case testValues[count] in range but not found
                s = Status::IN_RANGE_NOT_FOUND;

                // index conventionally set to -2
                index = -2;
            }
        }
        else { 
            
            // testValues[count] found
            s = Status::FOUND;

            // index of element found is calculated as distance between the iterator to the beginning 
            // of the array and the iterator to the first element found
            index = p.first - array.begin();
        }

        // If it matches our expected value, then great!
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed! (element: "<< printStatus(s) <<")\n";
        else // otherwise, our binarySearch() function must be broken
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code! (element "<< testValues[count]  << ": " << printStatus(s) << " with index " << index << " but expected: " << expectedValues[count] << ")\n";
    }

    return 0;
}