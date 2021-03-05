#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;
using std::ostream;

// A helper function for printing vectors.
template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v); 

class Foo{
    // Assume n = targetSum, numbers array size = m
    public:
    // Memoization - Time O(n*m^2) Space O(n)
    vector<int> howSum(const int& n, const vector<int>& numbers, map<int, vector<int>>& map)
    {
        if (map.count(n) == 1)  return map[n];

        if (n == 0) return {0}; 
        if (n < 0) return {};

        for (const auto& num : numbers)
        {
            const int reminder = n - num;
            auto reminderResult = howSum(reminder, numbers, map);
            if (reminderResult.size() != 0) // if vector is not null
            {
                reminderResult.push_back(num);
                map[n] = vector<int>(reminderResult);
                return map[n];
            }
        }
        map[n] = {};
        return {};
    }
    // Brute Force - Time O(m^n * n) Space O(n)
    vector<int> howSum(const int& n, const vector<int>& numbers)
    {
        if (n == 0) return {0}; 
        if (n < 0) return {};

        for (const auto& num : numbers)
        {
            const int reminder = n - num;
            auto reminderResult = howSum(reminder, numbers);
            if (reminderResult.size() != 0) // if vector is not null
            {
                reminderResult.push_back(num);
                return vector<int>(reminderResult);
            }
        }
        return {};
    }
};

int main(void)
{
    Foo foo;
    map<int, vector<int>> map;                                          // clean content of map each time
    std::cout << foo.howSum(7, vector<int>{2,3}, map) << std::endl;     map = {};
    std::cout << foo.howSum(7, vector<int>{5,3,4,7}, map) << std::endl; map = {};
    std::cout << foo.howSum(7, vector<int>{2,4}, map) << std::endl;     map = {};
    std::cout << foo.howSum(8, vector<int>{2,3,5}, map) << std::endl;   map = {};
    std::cout << foo.howSum(300, vector<int>{7,14},map) << std::endl;   map = {};
}

// helper function for writing vectors easily. 
template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "{";
    size_t last = v.size() - 1;
    for(size_t i = 1; i < v.size(); ++i) {
        out << v[i];
        if (i != last) 
            out << ", ";
    }
    out << "}";
    return out;
}