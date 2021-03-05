#include <iostream>
#include <vector>

using std::vector;

class Foo
{
    public:
    int gridTraveler(const int& m, const int& n)
    {
        vector<vector<int>> table(m+1,vector<int>(n+1,0)); // create table with m+1 * n+1 size and fill with zeros
        table[1][1] = 1;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                const int current = table[i][j];
                if (i+1 <= m) table[i+1][j] += current;
                if (j+1 <= n) table[i][j+1] += current;
            }
        }
        return table[m][n];
    }
};

int main(void)
{
    Foo foo;
    std::cout << foo.gridTraveler(1,1) << std::endl;
    std::cout << foo.gridTraveler(2,3) << std::endl;
    std::cout << foo.gridTraveler(3,2) << std::endl;
    std::cout << foo.gridTraveler(3,3) << std::endl;
    std::cout << foo.gridTraveler(10,14) << std::endl;
}
