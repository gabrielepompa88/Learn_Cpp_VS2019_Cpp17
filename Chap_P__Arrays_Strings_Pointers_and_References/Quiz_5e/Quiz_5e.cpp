/* ORIGINAL CODE SNIPPET (wrong)
* 
int main()
{
  double d{ 5.5 };
  int* ptr{ &d };
  std::cout << ptr << '\n';

  return 0;
}

ERROR: cannot assign memory address of double variable (d) to pointer to int (ptr).
Solution: make ptr a double*
*/

# include <iostream>

int main()
{
	double d{ 5.5 };
	double* ptr{ &d };
	std::cout << ptr << '\n';

}