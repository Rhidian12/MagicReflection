#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

#include "MagicReflection.h"

struct FooBar
{

};

template<typename T, typename U>
class TemplatedClass
{

};

int main()
{
    {
        FooBar Foo{};
        std::cout << MRFL_GET_TYPE_NAME(Foo) << "\n\n";
    }

    {
        std::vector<FooBar> Foo{};
        std::cout << MRFL_GET_TYPE_NAME(Foo) << "\n\n";
    }

    {
        std::map<int, int> Foo{};
        std::cout << MRFL_GET_TYPE_NAME(Foo) << "\n\n";
    }

    {
        std::unordered_map<int, FooBar> Foo{};
        std::cout << MRFL_GET_TYPE_NAME(Foo) << "\n\n";
    }

    {
        TemplatedClass<int, int> Foo{};
        std::cout << MRFL_GET_TYPE_NAME(Foo) << "\n\n";
    }

    {
        TemplatedClass<double, float> Foo{};
        std::cout << MRFL_GET_TYPE_NAME(Foo) << "\n\n";
    }

    {
        TemplatedClass<int, FooBar> Foo{};
        std::cout << MRFL_GET_TYPE_NAME(Foo) << "\n\n";
    }
}