#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <array>
#include "func.h"
#include "Words.h"

using namespace std;

Words funcWords;
string name, selection, word, input, pass;
string constWord, constWordUnlocked;
int score, level;
bool loop;
vector<string> wordsEasy;
vector<string> wordsNormal;
vector<string> wordsHard;

void ResetVars()
{
    loop = true;
    constWord = funcWords.get_word(level);
    constWordUnlocked = "";
    wordsEasy = funcWords.get_listEasy(level);
    wordsNormal = funcWords.get_listNormal(level);
    wordsHard = funcWords.get_listHard(level);
}
int main()
{
    score = 0;
    level = 1;
    pass = "pass";

    cout << "Enter your name: ";
    cin >> name;
    
    system("cls");
    
    cout << "Hi " + name + "! Ready to play some word puzzle?\nTip: Enter yes to continue. Else, enter no to exit the program." << endl;
    cout << "Type here: ";
    cin >> selection;
    transform(selection.begin(), selection.end(), selection.begin(), ::tolower);
    if (selection.compare("yes") == 0)
    {
        // Reset vars
        ResetVars();

        cout << "Okay " + name + ", let's go to the EASY Round!" << endl;
        system("cls");
        while (loop)
        {
            system("cls");
            cout << "Round 1: " << word << endl;
            cout << "Tip: You have " << wordsEasy.size() << " three-letter words left to guess. Type \"" << pass << "\" to move on to the next round. Goodluck!" << endl;
            cout << "Your current score is: " << score << endl;
            cout << "Unlocked words: " << constWordUnlocked << endl << endl;
            cout << "Type your guess here: ";
            cin >> input;
            transform(input.begin(), input.end(), input.begin(), ::tolower);
            if (input.compare(pass) == 0 || wordsEasy.size() < 1)
            {
                loop = false;
            }
            else
            {
                if (find_word(wordsEasy, input))
                {
                    cout << input << " is one of the answer. You got +1 point!" << endl << endl;
                    ++score;
                    if (constWordUnlocked != "")
                    {
                        constWordUnlocked = constWordUnlocked + ", ";
                    }
                    constWordUnlocked = constWordUnlocked + input;
                }
                else
                {
                    cout << input << " is not in dictionary! Try again." << endl << endl;
                }
            }
        }
        

        cout << "End of program.";
    }
    
    return 0;
}