#include <iostream>
#include <map>

typedef unsigned long long int longint;
using std::map;

class Foo{
    public:
    // Memoization - Time O(n) Space O(n)
    int fib(const int& n, map<int, longint>& map) // there is no way I could found default argument with reference.
    {
        if (map.count(n) == 1) return map[n];
        if (n <= 2) return 1;
        map[n] = fib(n-1, map) + fib(n-2, map);
        return map[n];
    }
    // Brute Force - Time O(2^n) Space O(n)
    int fib(const int& n)
    {    
        if (n <= 2) return 1;
        return fib(n-1) + fib(n-2); 
    }
};

int main(void)
{
    map<int, longint> map;
    Foo foo;
    std::cout << foo.fib(5,map) << std::endl;
    std::cout << foo.fib(6,map) << std::endl;
    std::cout << foo.fib(7,map) << std::endl;
    std::cout << foo.fib(8,map) << std::endl;
    std::cout << foo.fib(20,map) << std::endl;
    std::cout << foo.fib(45,map) << std::endl;
    std::cout << foo.fib(46,map) << std::endl;
}