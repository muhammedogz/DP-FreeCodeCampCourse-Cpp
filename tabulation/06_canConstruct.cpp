#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::string;


class Foo{
    public:
    bool canConstruct(const string& target, const vector<string>& wordBank)
    {
        vector<bool> table(target.size() + 1, false);
        table[0] = true;
        for (int i = 0; i <= target.size(); i++)
        {
            if (table[i] == true)
            {
                for (const auto& word : wordBank)
                {
                    if (target.substr(i, word.size()) == word)
                    {
                        table[i + word.size()] = true;
                    }    
                }
            }
        }
        return table[target.size()];
    }
};


int main(void)
{
    Foo foo;
    std::cout << foo.canConstruct("abcdef", {"ab","abc","cd","def","abcd"}) << std::endl;
    std::cout << foo.canConstruct("skateboard", {"bo","rd","ate","t","ska","sk","boar"}) << std::endl;
    std::cout << foo.canConstruct("enterapotentpot", {"a","p","ent","enter","ot","o","t"}) << std::endl;
    std::cout << foo.canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {
       "e",
       "ee",
       "eee",
       "eeee",
       "eeeee",
       "eeeeee"}) << std::endl;   

}

