#include <iostream>
#include <string>
#include <memory> // To access the smart pointers you will need to include the "memory" library

// Smart Pointers (Unique, Shared, Weak) in C++

/*
    Unique Pointers have to be unique, you can't copy them, if you did, you would have two unique pointers pointing at the same address in memory
    and when one of them gets freed, the other would be pointing to memory that's been free'd and will cause a memory leak.
*/

// Example Entity class
class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Created Entity" << std::endl;
    }
};

int main()
{

    std::cin.get();
}
