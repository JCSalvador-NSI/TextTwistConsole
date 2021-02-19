#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

string mix_letters(string s)
{
    vector<int> num;
    string word = "";
    for (int c=0; c<s.size(); ++c)
    {
        num.push_back(c);
    }
    auto rng = default_random_engine {};
    shuffle(begin(num), end(num), rng);
    for (int it : num)
    {
        word = word + s.substr(it, 1);
    }
    return word;
}

bool find_word(vector<string> &sList, string word)
{
    auto it = find(sList.begin(), sList.end(), word);
    if (it != sList.end())
    {
        sList.erase(it);
        return true;
    }
    return false;
}