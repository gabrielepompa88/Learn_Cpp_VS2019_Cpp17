#include <cassert> // for assert()
#include <iostream>

class IntArray {

	int m_len;
	int *m_arr;

public:

	IntArray(int len) : m_len(len) {
		std::cout << "normal constructor called\n";

		delete[] m_arr;
		m_arr = new int[m_len];
	}

	void deepCopy(const IntArray& source_arr);

	//(deep)copy constructor
	IntArray(const IntArray& source_arr){

		std::cout << "Copy constructor called\n";

		// deep-copying
		deepCopy(source_arr);

	}

	//overloaded operator=
	IntArray& operator=(const IntArray& source_arr) {

		std::cout << "Overloaded operator= called\n";

		// self-assignment check
		if (this == &source_arr)
			return *this;

		// deep-copying
		deepCopy(source_arr);

		// returning reference to called object for chaining 
		return *this;

	}

	//overloaded operator[]
	int& operator[](int i) const {
		assert(i >= 0 && i < m_len && "Index out of range");

		return m_arr[i];
	}

	friend std::ostream& operator<<(std::ostream& out, const IntArray& source_arr) {
		for (int i = 0; i < source_arr.m_len; ++i) {
			out << source_arr.m_arr[i] << " ";
		}
		return out;
	}

	//destructor
	~IntArray() {
		delete[] m_arr;
	}
};

void IntArray::deepCopy(const IntArray& source_arr) {

	// first we need to deallocate any value that this array is holding!
	// to avoid memory leaks if we reassign it to with a new dynamically allocated memory (on line 80)
	delete[] m_arr;

	// because m_len is not a pointer, we can shallow copy it
	m_len = source_arr.m_len;

	// m_arr is a pointer, so we need to deep copy it if it is non-null
	if (source_arr.m_arr)
	{
		// allocate memory for our copy
		m_arr = new int[m_len];

		// do the copy
		for (int i{ 0 }; i < m_len; ++i)
			m_arr[i] = source_arr.m_arr[i];
	}
	else
		m_arr = nullptr;
}

IntArray fillArray()
{
	std::cout << "in fillArray(): IntArray a(5); --> ";
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	std::cout << "in main: IntArray a{ fillArray() }; --> \n";
	IntArray a{ fillArray() };
	std::cout << a << '\n';

	std::cout << "\nauto& ref{ a }; --> ";
	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	std::cout << "\na = ref; --> ";
	a = ref;

	std::cout << "\nIntArray b(1); --> ";
	IntArray b(1);
	std::cout << "\nb = a; --> ";
	b = a;

	std::cout << b << '\n';

	return 0;
}