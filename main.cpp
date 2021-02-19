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
int score, level, wordListSize, roundCount;
bool loop, newRound;
vector<string> wordsEasy;
vector<string> wordsNormal;
vector<string> wordsHard;
vector<string> wordsCurrent;
vector<string> roundTitle = { "EASY", "NORMAL", "HARD" };
vector<string> roundLetter = { "three", "four", "five" };

void ResetVarsPerLevel()
{
    loop = true;
    constWord = funcWords.get_word(level);
    constWordUnlocked = "";
    wordsEasy = funcWords.get_listEasy(level);
    wordsNormal = funcWords.get_listNormal(level);
    wordsHard = funcWords.get_listHard(level);
    word = mix_letters(constWord);
}
void ResetVarPerRound()
{
    cout << "Okay " + name + ", let's go to the " << roundTitle[roundCount-1] << " Round!" << endl;
    if (newRound)
    {
        word = mix_letters(word);
        wordsCurrent.clear();
        switch (roundCount)
        {
            case 1:
                wordsCurrent = wordsEasy;
                break;
            case 2:
                wordsCurrent = wordsNormal;
                break;
            case 3:
                wordsCurrent = wordsHard;
                break;
        }
        wordListSize = wordsCurrent.size();
    }
}
bool MoveToNextRound()
{
    ++roundCount;
    if (roundCount > 3)
    {
        roundCount = 1;
        //returns false, moves to next level instead
        return false;
    }
    return true;
}

int main()
{
    score = 0;
    level = 1;
    roundCount = 1;
    newRound = true;
    pass = "pass";

    cout << "Enter your name: ";
    cin >> name;
    
    system("cls");
    
    cout << "Hi " + name + "! Ready to play some word puzzle?\nTip: Enter 'yes' to continue. Else, enter no to exit the program." << endl;
    cout << "Type here: ";
    cin >> selection;
    transform(selection.begin(), selection.end(), selection.begin(), ::tolower);
    if (selection.compare("yes") == 0)
    {
        while (level <= 2)
        {
            system("cls");
            ResetVarsPerLevel();
            
            while (loop)
            {
                system("cls");
                ResetVarPerRound();
                
                cout << "Level " << level << " Round " << roundCount << ": " << word << endl;
                cout << "Tip: You have " << wordListSize << " " << roundLetter[roundCount-1] << "-letter word(s) left to guess. Type \"" << pass << "\" to move on to the next round. Goodluck!" << endl;
                cout << "Your current score is: " << score << endl;
                cout << "Unlocked words: " << constWordUnlocked << endl << endl;
                cout << "Type your guess here: ";
                cin >> input;
                transform(input.begin(), input.end(), input.begin(), ::tolower);
                if (input.compare(pass) == 0)
                {
                    newRound = true;
                    loop = MoveToNextRound();
                }
                else
                {
                    newRound = false;
                    if (find_word(wordsCurrent, input))
                    {
                        cout << input << " is one of the answer. You got +1 point!" << endl << endl;
                        ++score;
                        if (constWordUnlocked != "")
                        {
                            constWordUnlocked = constWordUnlocked + ", ";
                        }
                        constWordUnlocked = constWordUnlocked + input;
                        wordListSize = wordsCurrent.size();
                        if (wordListSize < 1)
                        {
                            cout << "You guessed all the correct words! Moving on.." << endl;
                            newRound = true;
                            loop = MoveToNextRound();
                        }
                    }
                    else
                    {
                        cout << input << " is not in dictionary! Try again." << endl << endl;
                    }
                    //system("pause");
                }
            }

            ++level;
        }

        cout << "End of program.";
    }
    
    return 0;
}