#include<iostream>

//p is a (non-const) reference to a const-ptr to int type
void changeContent(int* const &p) {
	*p = 17;

	/* This: 	

	int y = 17;
	p = &y;
	 
	or this:
	
	p = nullptr;
	
	would cause the error of re-assigning a const-ptr:
	" 'p': you cannot assign to a variable that is const. "
	
	which is the same behavior of a const-ref to the pointer.
	
	and if the signature is changed to (int* &p), the *p_x in the main, 
	when changeContent returns, is an undefined behavior, because p_x will point
	to the address in memory originally allocated to 'y', 
	but that memory does not contain 17 anymore because it has been freed 
	when y goes out of scope at the end of changeContent.
	*/
	}

//p is a (non-const) reference to a (non-const) ptr to int type
void changePointer(int* &p) {
	p = nullptr;
}

int main() {

	int x = 3;
	int *p_x = &x;

	std::cout << "Originally:\n";
	std::cout << "p_x == " << p_x << " - *p_x == " << *p_x << "\n\n";

	changeContent(p_x);
	std::cout << "After changeContent:\n";
	std::cout << "p_x == " << p_x << " - *p_x == " << *p_x << "\n\n";

	changePointer(p_x);
	if (!p_x)
		std::cout << "After changePointer: p_x is a nullptr.\n\n";

	// Another example of const/non-const ptr

	int z = 5;
	int *p_z = &z;
	std::cout << "p_z == " << p_z << " - *p_z == " << *p_z << "\n\n";
	int * const pc_z = p_z;
	std::cout << "pc_z == " << pc_z << " - *pc_z == " << *pc_z << "\n\n";

	p_z = nullptr;
	if (!p_z)
		std::cout << "After reassignment: p_z is a nullptr.\n\n";

	// wherease this below would cause the const-assignment erro
	// 'pc_z': you cannot assign to a variable that is const
	// pc_z = nullptr;

	return 0;

}