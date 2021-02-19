#include <iostream>
#include <map>

class Foo{
    public:
    int fib(const int& n, std::map<int,unsigned long long int>& map) // there is no way I could found default argument with reference.
    {
        if (map.count(n) == 1) return map[n];
        if (n <= 2) return 1;
        map[n] = fib(n-1, map) + fib(n-2, map);
        return map[n];
    }
};

int main(void)
{
    std::map<int,unsigned long long int> map;
    Foo foo;
    std::cout << foo.fib(5,map) << std::endl;
    std::cout << foo.fib(6,map) << std::endl;
    std::cout << foo.fib(7,map) << std::endl;
    std::cout << foo.fib(8,map) << std::endl;
    std::cout << foo.fib(20,map) << std::endl;
    std::cout << foo.fib(45,map) << std::endl;
    std::cout << foo.fib(46,map) << std::endl;
}