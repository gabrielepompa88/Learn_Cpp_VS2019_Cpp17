/* ORIGINAL CODE SNIPPET (wrong)

int main()
{
  int x{ 5 };
  int y{ 7 };

  const int* ptr{ &x };
  std::cout << *ptr << '\n';
  *ptr = 6;
  std::cout << *ptr << '\n';
  ptr = &y;
  std::cout << *ptr << '\n';

  return 0;
}

ERROR: ptr is (non-const) pointer to const int, therefore the assignment *ptr = 6 is not possible.
Below I correct it declaring ptr a (non-const) pointer to (non-const) int.
*/

#include <iostream>

int main()
{
	int x{ 5 };
	int y{ 7 };

	int* ptr{ &x };
	std::cout << *ptr << '\n';
	*ptr = 6;
	std::cout << *ptr << '\n';
	ptr = &y;
	std::cout << *ptr << '\n';

	return 0;
}