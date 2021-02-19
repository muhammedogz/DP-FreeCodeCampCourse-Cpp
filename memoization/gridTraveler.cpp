#include <iostream>
#include <string>
#include <map>

typedef unsigned long long int longint;
using std::map;
using std::string;
using std::to_string;

class Foo{
    public:
    // Memoization - Time O(n*m) Space O(n+m)
    int gridTraveler(const int& n, const int& m, map<string, longint>& map) 
    {
        const string key = to_string(n) + "," + to_string(m); // create key
        if (map.count(key) == 1) return map[key];

        if (n == 0 || m == 0) return 0;
        if (n == 1 && m == 1) return 1;
        map[key] = gridTraveler(n-1,m,map) + gridTraveler(n, m-1,map);
        
        return map[key];
    }
    // Brute Force - Time O(2^(n+m)) Space O(n+m)
    int gridTraveler(const int& n, const int& m) 
    {
        if (n == 0 || m == 0) return 0;
        if (n == 1 && m == 1) return 1;
        return gridTraveler(n-1,m) + gridTraveler(n, m-1);
    }
};

int main(void)
{
    map<string ,longint> map;
    Foo foo;
    std::cout << foo.gridTraveler(1,1,map) << std::endl;
    std::cout << foo.gridTraveler(2,3,map) << std::endl;
    std::cout << foo.gridTraveler(3,2,map) << std::endl;
    std::cout << foo.gridTraveler(3,3,map) << std::endl;
    std::cout << foo.gridTraveler(10,14,map) << std::endl;
}