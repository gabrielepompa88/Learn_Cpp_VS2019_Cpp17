#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	// PROBLEM: both ptr1 and ptr2 point to res, but they are no aware of the other,
	// so the first that goes out of scope, deletes the Resource, leaving dangling the other one.
	// Resource* res = new Resource;
	// std::shared_ptr<Resource> ptr1(res);
	// std::shared_ptr<Resource> ptr2(res);

	// SOLUTION: use copy-semantics to share Resource between two shared_ptr
	// Resource* res = new Resource;
	// std::shared_ptr<Resource> ptr1(res);
	// std::shared_ptr<Resource> ptr2{ptr1};

	// BETTER SOLUTION: use std::make_shared, which makes impossible the error above
	auto ptr1{ std::make_shared<Resource>() };
	std::shared_ptr<Resource> ptr2{ ptr1 };

	return 0;
}