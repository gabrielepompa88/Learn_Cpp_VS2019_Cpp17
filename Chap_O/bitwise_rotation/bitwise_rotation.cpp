#include <iostream>
#include <bitset>

std::bitset<4> bit_rotate(std::bitset<4> bits)
{
	bool leftbit = bits.test(3); // take the leftmost bit
	bits <<= 1; // left shift
	if (leftbit) { bits.set(0); } // set to 1 the rightmost bit (0), if necessary

	return bits;
}

int main()
{
	std::bitset<4> x{ 0b0001 };
	std::cout << bit_rotate(x) << '\n';

	std::bitset<4> y{ 0b1001 };
	std::cout << bit_rotate(y) << '\n';

	return 0;
}