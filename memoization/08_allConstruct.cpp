#include <iostream>
#include <map>
#include <vector>
#include <string>

using std::map;
using std::vector;
using std::string;
using std::ostream;

// A helper function for printing vectors.
template<typename T>
ostream& operator<< (ostream& out, const vector<vector<T>>& v); 


class Foo{
    public: // m =  target.size(), n = wordBank.length()
    // Memoization - Time O(n^m) Space (m)
    vector<vector<string>> allConstruct(const string& target, const vector<string>& wordBank,
    map<string, vector<vector<string>>>& map)
    {
        if (map.count(target) == 1) return map[target];
        if (target.size() == 0) return {{}};

        vector<vector<string>> result;

        for (const auto& word : wordBank)
        {
            if (target.find(word) == 0)
            {
                const string suffix = target.substr(word.size(), target.size());
                const vector<vector<string>> suffixWays = allConstruct(suffix, wordBank, map);
                vector<vector<string>> targetWays = targetWaysHelper(suffixWays, word);
                result.insert(result.end(), targetWays.begin(), targetWays.end());
            }
        }

        map[target] = result;
        return result;
    }
    // Brute Force -
    vector<vector<string>> allConstruct(const string& target, const vector<string>& wordBank)
    {
        if (target.size() == 0) return {{}};

        vector<vector<string>> result;

        for (const auto& word : wordBank)
        {
            if (target.find(word) == 0)
            {
                const string suffix = target.substr(word.size(), target.size());
                const vector<vector<string>> suffixWays = allConstruct(suffix, wordBank);
                vector<vector<string>> targetWays = targetWaysHelper(suffixWays, word);
                result.insert(result.end(), targetWays.begin(), targetWays.end());
            }
        }

        return result;
    }
    // Helper function for copying words to vector. 
    // In JavaScript: targetWays = suffixWays.map(way => [word,...way])
    private:
    vector<vector<string>> targetWaysHelper(const vector<vector<string>>& vec, const string& word)
    {
        vector<vector<string>> res;
        int track = 0;
        for (auto v : vec)
        {
            v.insert(v.begin(), word);
            res.push_back(v);
        }
        return res;
    }
};


int main(void)
{
    map<string, vector<vector<string>>> map;
    Foo foo;
    std::cout << foo.allConstruct("purple", {"purp","p","ur","le","purpl"}, map) << std::endl;
    std::cout << foo.allConstruct("abcdef", {"ab","abc","cd","def","abcd"}, map) << std::endl;
    std::cout << foo.allConstruct("skateboard", {"bo","rd","ate","t","ska","sk","boar"}, map) << std::endl;
    std::cout << foo.allConstruct("enterapotentpot", {"a","p","ent","enter","ot","o","t"}, map) << std::endl;
    std::cout << foo.allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {
        "e",
        "ee",
        "eee",
        "eeee",
        "eeeee",
        "eeeeee"}, map) << std::endl;   

}



// helper function for writing vectors easily. 
template<typename T>
ostream& operator<< (ostream& out, const vector<vector<T>>& v) {
    out << "{";
    int last = v.size() - 1;
    for(int i = 0; i < v.size(); ++i) 
    {
        out << "{";
        int lastInner = v[i].size() - 1;
        for (int j = 0; j < v[i].size(); j++)
        {
            out << v[i][j];
            if (j != lastInner)
                out << ", ";
        }
        out << "}";
        if (i != last) 
            out << ", " << std::endl;
    }
    out << "}";
    return out;
}

