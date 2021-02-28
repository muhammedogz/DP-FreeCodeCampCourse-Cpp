#include <iostream>
#include <map>
#include <vector>
#include <string>

using std::map;
using std::vector;
using std::string;


class Foo{
    public: // m =  target.size(), n = wordBank.length()
    // Memoization - Time O(n* m^2 ) Space (m^2)
    bool canConstruct(const string& target, const vector<string>& wordBank, map<string, bool>& map)
    {
        if (map.count(target) == 1) return map[target];
        if (target.size() == 0) return true;

        for (auto& word : wordBank)
        {
            if (target.find(word) == 0)
            {
                const string suffix = target.substr(word.size(), target.size());
                if (canConstruct(suffix, wordBank, map))
                {
                    map[target] = true;
                    return true;
                }
            }
        }
        map[target] = false;
        return false;
    }
    // Brute Force - Time O(n^m * m ) Space (m^2)
    bool canConstruct(const string& target, const vector<string>& wordBank)
    {
        if (target.size() == 0) return true;

        for (auto& word : wordBank)
        {
            if (target.find(word) == 0)
            {
                const string suffix = target.substr(word.size(), target.size());
                if (canConstruct(suffix, wordBank))
                {
                    return true;
                }
            }
        }
        return false;
    }
};


int main(void)
{
    map<string, bool> map;
    Foo foo;
    std::cout << foo.canConstruct("abcdef", {"ab","abc","cd","def","abcd"}, map) << std::endl;
    std::cout << foo.canConstruct("skateboard", {"bo","rd","ate","t","ska","sk","boar"}, map) << std::endl;
    std::cout << foo.canConstruct("enterapotentpot", {"a","p","ent","enter","ot","o","t"} ,map) << std::endl;
    std::cout << foo.canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {
        "e",
        "ee",
        "eee",
        "eeee",
        "eeeee",
        "eeeeee"}, map) << std::endl;   

}

