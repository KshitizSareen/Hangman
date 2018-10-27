#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<locale>
#include "Hangman.h"
using namespace std;

int Hangman::UI()//The UI function
{
    int c;
    cout<<"Welcome to Hangman"<<"\n";
    cout<<"Please choose your difficulty"<<"\n";
    cout<<"1) Easy"<<"\n";
    cout<<"2) Medium"<<"\n";
    cout<<"3) Hard"<<"\n";
    while(c!=1)
    {
        cin>>difficulty;  //Choosing the difficulty
        if(difficulty==1)
        {
            wordseasy.insert(wordseasy.begin(),"cat");/* Inserting words in word easy for difficulty easy */
            wordseasy.insert(wordseasy.begin(),"moon");
            wordseasy.insert(wordseasy.begin(),"door");
            wordseasy.insert(wordseasy.begin(),"flight");
            break;
        }
        else if(difficulty==2)
        {
        	wordsmedium.insert(wordsmedium.begin(),"random");/* Inserting words in word medium for difficulty medium */
        	wordsmedium.insert(wordsmedium.begin(),"nationalism");
        	wordsmedium.insert(wordsmedium.begin(),"travel");
        	wordsmedium.insert(wordsmedium.begin(),"fearfull");
            break;
        }
        else if(difficulty==3)
        {
        	wordsdifficult.insert(wordsdifficult.begin(),"socialism");/* Inserting words in worddifficulty for difficulty hard */
        	wordsdifficult.insert(wordsdifficult.begin(),"extravaganza");
        	wordsdifficult.insert(wordsdifficult.begin(),"enthusiasm");
        	wordsdifficult.insert(wordsdifficult.begin(),"formidable");
            break;
        }
        else
        {
            cout<<"Please choose a valid number"<<"\n";
            c=0;
        }

    }
    return difficulty;
    system("CLS");
}
void Hangman::Random(int difficulty)/*Choosing a random word*/
{
	srand(time(NULL));
    if(difficulty==1)
    word=wordseasy[rand()%wordseasy.size()];
    else if(difficulty==2)
    word=wordsmedium[rand()%wordsmedium.size()];
    else if(difficulty==3)
    word=wordsdifficult[rand()%wordsdifficult.size()];
}
int Hangman::Input()
{
	cout<<"you have 7 tries remaining"<<"\n";
	char blankstring[word.size()];//Inserting a blank string
	for(int k=0;k<word.size();k++)
	blankstring[k]='_';
    int a=0,b=0,pen=0,j=0;
    cout<<"The word length is "<<word.size()<<"\n";
    cout<<"Please Enter a letter"<<"\n";
    while(1)
    {
    cin>>letter;
    while(j<=letters.size())
    {
        if(letters.size()==0)
            break;

    	if(letters[j]==letter || (letters[j]-32)==letter)       /*Code for selecting and filtering letters that have not been selected*/
    	{
    		cout<<"Please select a letter which you have not entered"<<"\n";
    		cin>>letter;
    		j=0;
		}
		else
		j++;
	}
	letters.insert(letters.end(),letter);
	j=0;

    for(int i=0;i<word.size();i++)
    {
        if(word[i]==letter || (word[i]-32)==letter) //Comparing the letters with the word
        {
            blankstring[i]=letter;
            b++;
        }
        else
        {
            a++;
        }
        if(a==(word.size()))
        {
        	pen++;
        	cout<<"You have "<< 7-pen <<" tries remainig"<<"\n";
        	break;
		}
	}
	a=0;
	cout<<blankstring<<"\n";

    	if(pen==1 && b!=word.size())
    	{
    		Output(pen,b);
		}
		else if(pen==2 && b!=word.size())
    	{
    		Output(pen,b);
		}
		else if(pen==3 && b!=word.size())
    	{
    		Output(pen,b);
		}
		else if(pen==4 && b!=word.size())
    	{
    		Output(pen,b);
		}
		else if(pen==5 && b!=word.size())
    	{
    		Output(pen,b);
		}
		else if(pen==6 && b!=word.size())
    	{
    		Output(pen,b);
		}
		else if(pen==7 && b!=word.size())
    	{
    			Output(pen,b);
    			break;
		}
		if(b==(word.size()))
		{
			 Output(pen,b);
			 break;
		}

	}
}
void Hangman::Output(int pen,int won)
{
	if(won==word.size())
	{
	cout<<"You won"<<"\n";
	return;
	}

	if(pen==7)
	{
		cout<<"----------------------------------------"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"             -----"<<"\n";
		cout<<"|"<<"             |   |"<<"\n";
		cout<<"|"<<"             -----"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"         ------|------"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"              | | "<<"\n";
		cout<<"|"<<"              | |"<<"\n";
		cout<<"|"<<"              | |"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"You lost"<<"\n";
		cout<<"The word is "<<word;
		return;

	}
	else if(pen==6)
	{
		cout<<"----------------------------------------"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"             -----"<<"\n";
		cout<<"|"<<"             |   |"<<"\n";
		cout<<"|"<<"             -----"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"         ------|------"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"              |  "<<"\n";
		cout<<"|"<<"              |   "<<"\n";
		cout<<"|"<<"              |     "<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";

	}
	else if(pen==5)
	{
		cout<<"----------------------------------------"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"             -----"<<"\n";
		cout<<"|"<<"             |   |"<<"\n";
		cout<<"|"<<"             -----"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"         ------|------"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"                "<<"\n";
		cout<<"|"<<"                 "<<"\n";
		cout<<"|"<<"                "<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";

	}
	else if(pen==4)
	{
		cout<<"----------------------------------------"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"             -----"<<"\n";
		cout<<"|"<<"             |   |"<<"\n";
		cout<<"|"<<"             -----"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"         ------|"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"                "<<"\n";
		cout<<"|"<<"                 "<<"\n";
		cout<<"|"<<"                "<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";

	}
	else if(pen==3)
	{
		cout<<"----------------------------------------"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"             -----"<<"\n";
		cout<<"|"<<"             |   |"<<"\n";
		cout<<"|"<<"             -----"<<"\n";
		cout<<"|"<<"               | "<<"\n";
		cout<<"|"<<"         	   | "<<"\n";
		cout<<"|"<<"               | "<<"\n";
		cout<<"|"<<"                 "<<"\n";
		cout<<"|"<<"                 "<<"\n";
		cout<<"|"<<"                 "<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";

	}
	else if(pen==2)
	{
		cout<<"----------------------------------------"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"             -----"<<"\n";
		cout<<"|"<<"             |   |"<<"\n";
		cout<<"|"<<"             -----"<<"\n";
		cout<<"|"<<"               "<<"\n";
		cout<<"|"<<"         	   "<<"\n";
		cout<<"|"<<"               "<<"\n";
		cout<<"|"<<"                "<<"\n";
		cout<<"|"<<"                 "<<"\n";
		cout<<"|"<<"                "<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";

	}
	else if(pen==1)
	{
		cout<<"----------------------------------------"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"               |"<<"\n";
		cout<<"|"<<"             "<<"\n";
		cout<<"|"<<"             "<<"\n";
		cout<<"|"<<"             "<<"\n";
		cout<<"|"<<"               "<<"\n";
		cout<<"|"<<"         	   "<<"\n";
		cout<<"|"<<"               "<<"\n";
		cout<<"|"<<"                "<<"\n";
		cout<<"|"<<"                 "<<"\n";
		cout<<"|"<<"                "<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";
		cout<<"|"<<"\n";


	}
}
int main()
{
	int difficulty,Result;
    Hangman H;
    difficulty=H.UI();
    H.Random(difficulty);
    H.Input();
}
