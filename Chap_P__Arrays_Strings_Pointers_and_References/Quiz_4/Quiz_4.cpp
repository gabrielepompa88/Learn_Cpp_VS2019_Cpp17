#include <iostream>

int main()
{
    // s pointer points to the first character: 'T'
    const char* s{"This is a C-style string!"};

    while (*s != '\0')
    {
        // print current character through indirection
        std::cout << *s << " ";

        // point to the following character, thanks to increment of the pointer
        ++s;
    }
}