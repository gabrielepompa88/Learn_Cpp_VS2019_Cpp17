// State which of the following lettered statements will not compile:

int main()
{
	int x{};

	// l-value references
	int& ref1{ x }; // A
	// int& ref2{ 5 }; // B: won't compile because l-value ref to non-const cannot be initialized with r-value

	const int& ref3{ x }; // C
	const int& ref4{ 5 }; // D

	// r-value references
	// int&& ref5{ x }; // E: won't compile because r-value ref cannot be initialized with l-values
	int&& ref6{ 5 }; // F

	//const int&& ref7{ x }; // G: same as E
	const int&& ref8{ 5 }; // H

	return 0;
}