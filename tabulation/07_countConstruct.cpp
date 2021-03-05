#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::string;


class Foo{
    public:
    int countConstruct(const string& target, const vector<string>& wordBank)
    {
        vector<int> table(target.size() + 1, 0);
        table[0] = 1;
        for (int i = 0; i <= target.size(); i++)
        {
            for (const auto& word : wordBank)
            {
                if (target.substr(i, word.size()) == word)
                {
                    table[i + word.size()] += table[i];
                }    
            }
        }
        return table[target.size()];
    }
};


int main(void)
{
    Foo foo;
    std::cout << foo.countConstruct("purple", {"purp","p","ur","le","purpl"}) << std::endl;
    std::cout << foo.countConstruct("abcdef", {"ab","abc","cd","def","abcd"}) << std::endl;
    std::cout << foo.countConstruct("skateboard", {"bo","rd","ate","t","ska","sk","boar"}) << std::endl;
    std::cout << foo.countConstruct("enterapotentpot", {"a","p","ent","enter","ot","o","t"}) << std::endl;
    std::cout << foo.countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {
       "e",
       "ee",
       "eee",
       "eeee",
       "eeeee",
       "eeeeee"}) << std::endl;   

}

