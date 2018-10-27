#include<iostream>
#include<vector>
#include<string>
#ifndef HANGMAN_H_INCLUDED
#define HANGMAN_H_INCLUDED
using namespace std;
class Hangman
{
    public:
        int UI();//The UI Function
        void Random(int difficulty);//THe random word generator function
        int Input();//The letter input and comparisonwith word function
        void Output(int pen,int won);//THe output function depending on the input.
    private: //Private variables
        int difficulty=0;
        vector<string> wordseasy;
        vector<string> wordsmedium;
        vector<string> wordsdifficult;
        vector<char> letters;
        string word;
        char letter;
};




#endif // HANGMAN_H_INCLUDED
