#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::string;
using std::ostream;

// A helper function for printing vectors.
template<typename T>
ostream& operator<< (ostream& out, const vector<vector<T>>& v); 

class Foo{
    public:
    vector<vector<string>> allConstruct(const string& target, const vector<string>& wordBank)
    {
        vector<vector<vector<string>>> table(target.size() + 1);
        table[0] = {{""}};
        for (int i = 0; i <= target.size(); i++)
        {
            if (table[i].size() != 0)
            for (const auto& word : wordBank)
            {
                if (target.substr(i, word.size()) == word)
                {
                    const auto newCombination = helper(table[i], word);
                    table[i + word.size()].insert(table[i + word.size()].begin(), newCombination.begin(), newCombination.end());
                }    
            }
        }
        return table[target.size()];
    }
    // Helper function for copying words to vector. 
    private:
    vector<vector<string>> helper(const vector<vector<string>>& vec, const string& word)
    {
        vector<vector<string>> res;
        for (auto v : vec)
        {
            v.push_back(word);
            res.push_back(v);
        }
        return res;
    }
};


int main(void)
{
    Foo foo;
    std::cout << foo.allConstruct("purple", {"purp","p","ur","le","purpl"}) << std::endl<< std::endl;
    std::cout << foo.allConstruct("abcdef", {"ab","abc","cd","def","abcd","ef","c"}) << std::endl<< std::endl;
    std::cout << foo.allConstruct("skateboard", {"bo","rd","ate","t","ska","sk","boar"}) << std::endl<< std::endl;
    std::cout << foo.allConstruct("aaaaaaaaaaz", {"a","aa","aaa","aaaa","aaaaa"}) << std::endl<< std::endl;
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
        for (int j = 1; j < v[i].size(); j++)
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
