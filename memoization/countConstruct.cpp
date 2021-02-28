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
    int countConstruct(const string& target, const vector<string>& wordBank, map<string,int>& map)
    {
        if (map.count(target) == 1) return map[target];
        if (target.size() == 0) return 1;

        int total = 0;

        for (auto& word : wordBank)
        {
            if (target.find(word) == 0)
            {
                const string suffix = target.substr(word.size(), target.size());
                total += countConstruct(suffix, wordBank,map);
            }
        }

        map[target] = total;
        return total;
    }
    // Brute Force - Time O(n^m * m ) Space (m^2)
    int countConstruct(const string& target, const vector<string>& wordBank)
    {
        if (target.size() == 0) return 1;

        int total = 0;

        for (auto& word : wordBank)
        {
            if (target.find(word) == 0)
            {
                const string suffix = target.substr(word.size(), target.size());
                total += countConstruct(suffix, wordBank);
            }
        }
        return total;
    }
};


int main(void)
{
    map<string, int> map;
    Foo foo;
    std::cout << foo.countConstruct("purple", {"purp","p","ur","le","purpl"},map) << std::endl;
    std::cout << foo.countConstruct("abcdef", {"ab","abc","cd","def","abcd"},map) << std::endl;
    std::cout << foo.countConstruct("skateboard", {"bo","rd","ate","t","ska","sk","boar"},map) << std::endl;
    std::cout << foo.countConstruct("enterapotentpot", {"a","p","ent","enter","ot","o","t"},map) << std::endl;
    std::cout << foo.countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {
        "e",
        "ee",
        "eee",
        "eeee",
        "eeeee",
        "eeeeee"},map) << std::endl;   

}

