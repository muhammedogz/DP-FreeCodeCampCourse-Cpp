#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;

class Foo{
    // Assume n = targetSum, numbers array size = m
    public:
    // Memoization - Time O(n*m) Space O(n)
    int canSum(const int& n, const vector<int>& numbers, map<int,bool>& map)
    {
        if (map.count(n) == 1) return map[n];

        if (n == 0) return true;
        else if (n < 0) return false;
        for (const auto& num: numbers)
        {
            const int reminder = n - num;
            if (canSum(reminder, numbers, map)) return true;
            else map[n] = false;
        }
        return false;
    }

    // Brute Force - Time O(m^n) Space O(n)
    int canSum(const int& n, const vector<int>& numbers)
    {
        if (n == 0) return true;
        else if (n < 0) return false;
        for (const auto& num: numbers)
        {
            const int reminder = n - num;
            if (canSum(reminder,numbers)) return true;
        }
        return false;
    }
};

int main(void)
{
    Foo foo;
    map<int,bool> map;
    std::cout << foo.canSum(7, vector<int>{2,3}, map) << std::endl;
    std::cout << foo.canSum(7, vector<int>{5,3,4,7}, map) << std::endl;
    std::cout << foo.canSum(7, vector<int>{2,4}, map) << std::endl;
    std::cout << foo.canSum(8, vector<int>{2,3,5}, map) << std::endl;
    std::cout << foo.canSum(300, vector<int>{7,14}, map) << std::endl;
}