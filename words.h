#include <string>
#include <vector>

using namespace std;

class Words
{
    public:
        int maxWords = 2;
        vector<string> words = { "VIDEO", "" };

        vector<vector<string>> wordsEasy =
        {
            { "dev", "die", "doe", "vid" },
            { "", "" }
        };

        vector<vector<string>> wordsNormal =
        {
            { "dive", "dove", "void" },
            { "", "" }
        };

        vector<vector<string>> wordsHard =
        {
            { "video" },
            { "", "" }
        };

        string get_word(int level)
        {
            level = (level > maxWords) ? maxWords : level;
            return words[level-1];
        }

        vector<string> &get_listEasy(int level)
        {
            level = (level > maxWords) ? maxWords : level;
            return wordsEasy[level-1];
        }

        vector<string> &get_listNormal(int level)
        {
            level = (level > maxWords) ? maxWords : level;
            return wordsNormal[level-1];
        }

        vector<string> &get_listHard(int level)
        {
            level = (level > maxWords) ? maxWords : level;
            return wordsHard[level-1];
        }
};