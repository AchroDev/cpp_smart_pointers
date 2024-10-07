#include <iostream>
#include <string>
#include <memory> // To access the smart pointers you will need to include the "memory" library

// Smart Pointers (Unique, Shared, Weak) in C++

/*
    Unique Pointers have to be unique, you can't copy them, if you did, you would have two unique pointers pointing at the same address in memory
    and when one of them gets freed, the other would be pointing to memory that's been free'd and will cause a memory leak.
*/

/*
    Shared pointers may differ by compiler. But it uses Reference Counting to keep track of how many references you have left that point to the memory
    address and once it hits 0, then it gets deleted
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
        std::cout << "Deleted Entity" << std::endl;
    }

    void Print() {}
};

int main()
{

    { // With a shared_ptr you can copy the object like here
        std::shared_ptr<Entity> e0;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); // This is declaring a shared ptr
            std::weak_ptr<Entity> weakEntity = sharedEntity;                   // You can use a weak_ptr with with a shared_ptr and it doesn't increase the ref count
            e0 = sharedEntity;                                                 // You can also assign a copy of the Entity here
        }
    }

    std::cin.get();
}
