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

    void Print() {}
};

int main()
{
    {
        // std::unique_ptr<Entity> entity = new Entity(); // Cannot do this due to the constructor for a unique pointer being explicit
        // std::unique_ptr<Entity> entity(new Entity()); // Has to be written this way due to the explicit requirement
        std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // The preferred way to write a uniqe pointer is to call make_unique for exception safety.

        entity->Print(); // Can access and call the Print function using the arrow operator
    }

    std::cin.get();
}
