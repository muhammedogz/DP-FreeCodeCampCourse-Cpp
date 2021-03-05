#include <iostream>
#include <vector>

using std::vector;
using std::ostream;

// A helper function for printing vectors.
template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v); 

class Foo
{
    public:
    vector<int> bestSum(const int& target,const vector<int>& nums)
    {
        vector<vector<int>> table(target + 1, 
        vector<int>(),{});
        table[0] = {0};
        for (int i = 0; i <= target; i++)
        {
            if (table[i].size() != 0)
            {
                for (const auto& num : nums)
                {
                    vector<int> temp = table[i];
                    temp.push_back(num);

                    if (i + num <= target && (table[i + num].size() == 0 || table[i + num].size() > temp.size())) table[i + num] = temp;
                }
            }
        }
        return table[target];
    }
};

int main(void)
{
    Foo foo;
    std::cout << foo.bestSum(7, {2,3}) << std::endl;
    std::cout << foo.bestSum(7, {5,3,4,7}) << std::endl;
    std::cout << foo.bestSum(7, {2,4}) << std::endl;
    std::cout << foo.bestSum(8, {2,3,5}) << std::endl;
    std::cout << foo.bestSum(300, {7,14}) << std::endl;
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