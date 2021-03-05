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
    // Memoized - Time O(n^2 * m) Space O(n^2)
    vector<int> bestSum(const int& n, const vector<int>& numbers, map<int, vector<int>>& map)
    {
        if (map.count(n) == 1) return map[n];
        if (n == 0) return {0}; 
        if (n < 0) return {};

        vector<int> shortestCombination; 

        for (const auto& num : numbers)
        {
            const int reminder = n - num;
            auto reminderCombination = bestSum(reminder, numbers,map);
            if (reminderCombination.size() != 0) // if vector is not null
            {
                reminderCombination.push_back(num);
                const vector<int> combination(reminderCombination);
                if (shortestCombination.size() == 0 || combination.size() < shortestCombination.size())
                    shortestCombination = combination;
            }
        }

        map[n] = shortestCombination;
        return shortestCombination;
    }
    // Brute Force - Time O(m^n * n) Space O(n^2)
    vector<int> bestSum(const int& n, const vector<int>& numbers)
    {
        if (n == 0) return {0}; 
        if (n < 0) return {};

        vector<int> shortestCombination; 

        for (const auto& num : numbers)
        {
            const int reminder = n - num;
            auto reminderCombination = bestSum(reminder, numbers);
            if (reminderCombination.size() != 0) // if vector is not null
            {
                reminderCombination.push_back(num);
                const vector<int> combination(reminderCombination);
                if (shortestCombination.size() == 0 || combination.size() < shortestCombination.size())
                    shortestCombination = combination;
            }
        }
        return shortestCombination;
    }
};

int main(void)
{
    Foo foo;
    map<int, vector<int>> map;                                          // clean content of map each time
    std::cout << foo.bestSum(7, vector<int>{5,3,4,7}, map) << std::endl;        map = {};
    std::cout << foo.bestSum(8, vector<int>{2,3,5}, map) << std::endl;          map = {};
    std::cout << foo.bestSum(8, vector<int>{1,4,5}, map) << std::endl;          map = {};
    std::cout << foo.bestSum(100, vector<int>{1,2,5,25}, map) << std::endl;     map = {};
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