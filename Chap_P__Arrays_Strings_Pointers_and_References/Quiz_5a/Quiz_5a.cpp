/* ORIGINAL CODE SNIPPET (wrong)

int main()
{
  int array[]{ 0, 1, 2, 3 };

  for (std::size_t count{ 0 }; count <= std::size(array); ++count)
  {
    std::cout << array[count] << ' ';
  }

  std::cout << '\n';

  return 0;
}

ERROR: one-by-off error.
*/

#include <iostream>

int main()
{
    int array[]{ 0, 1, 2, 3 };

    for (std::size_t count{ 0 }; count < std::size(array); ++count)
    {
        std::cout << array[count] << ' ';
    }

    return 0;
}