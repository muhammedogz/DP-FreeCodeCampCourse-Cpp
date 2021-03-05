#include <iostream>
#include <vector>

using std::vector;


class Foo
{
    public:
    bool canSum(const int& target,const vector<int>& nums)
    {
        vector<bool> table(target+1,false);
        table[0] = true;
        for (int i = 0; i <= target; i++)
        {
            if (table[i] == true)
            {
                for (const auto& num : nums)
                {
                    table[i + num] = true;
                }
            }
        }
        return table[target];
    }
};

int main(void)
{
    Foo foo;
    std::cout << foo.canSum(7, {2,3}) << std::endl;
    std::cout << foo.canSum(7, {5,3,4,7}) << std::endl;
    std::cout << foo.canSum(7, {2,4}) << std::endl;
    std::cout << foo.canSum(8, {2,3,5}) << std::endl;
    std::cout << foo.canSum(300, {7,14}) << std::endl;
}