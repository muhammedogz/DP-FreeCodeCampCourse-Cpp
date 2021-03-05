#include <iostream>
#include <vector>

typedef unsigned long long int longint;
using std::vector;

class Foo
{
public:
    longint fib(int n)
    {
        vector<longint> table(n + 1, 0);
        table[1] = 1;
        for (int i = 0; i <= n; i++)
        {
            table[i + 1] += table[i];
            table[i + 2] += table[i];
        }

        return table[n];
    }
};


int main(void)
{
    Foo foo;
    std::cout << foo.fib(6) << std::endl;
    std::cout << foo.fib(7) << std::endl;
    std::cout << foo.fib(8) << std::endl;
    std::cout << foo.fib(50) << std::endl;
}
