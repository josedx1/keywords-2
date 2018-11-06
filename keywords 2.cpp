//
//  Keywords 2.cpp
//  Keywords 2
//  Teacher: Tony Hilton
//  Created by Jose Rodriguez on 10/26/18.
//
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    for (int i = 0; i < 3; i++)
    {
        
        const int MAX_WRONG = 10;
        vector<string> words;
        string player; //Fixed This was an int
        // Create a collection of 10 words you had wrote down manually
        words.push_back("CIA");
        words.push_back("SPY");
        words.push_back("ENEMY");
        words.push_back("INVESTIGATION");
        words.push_back("FILE");
        words.push_back("BETRAYER");
        words.push_back("PATROL");
        words.push_back("ESPIONAGE");
        words.push_back("EMISSARY");
        
        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(words.begin(), words.end());
        
        const string THE_WORD = words[0];
        int wrong = 0;
        string soFar(THE_WORD.size(), '-');
        string used = "";
        
        // Display Title of program to user
        cout << "Welcome to Keywords 2 Code Breaker Training Simulation Program. Good luck! \n";
        
        // Ask the recruit to login using thier name
        cout << " Please Enter Your Name\n";
        // Hold the recruit's name in a var, and address them by it throughout the simulation.
        cin >> player;
        
        //Welcome the player
        cout << "\n\nWelcome " << player << endl; //
        // Display an overview of what Keywords II is to the recruit
        cout << " This training is to build you up, to be better and qualify for the CIA\n ";
        cout << " This program is going to be use to decode enemy transmission\n ";
        cout << " We are going to used a series of words of keyword and you will have to guess\n ";
        // Display an directions to the recruit on how to use Keywords
        cout << " We are going to select 3 keywords, you will try to guess the keyword\n";
        cout << " we are going to tell you how many incorrect guesse you make\n ";
        cout << " We will show you the letters of the keyword that you have guessed\n";
        cout << " We will ask you to type another guees and if you still incorrect but you word has letter part of the secrect word, we will add it on the word\n ";
        cout << " You got 10 tries to guess the keyword if not you will faild the program\n ";
        cout << " If you guess the secret keywords you will pass the program\n ";
        cout << " Are you ready to start this training Recruit?\n ";
        
        
        // While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
        while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
        {
            // Tell recruit how many incorrect guesses he or she has left
            cout << "\n\nYou have " << (MAX_WRONG - wrong);
            cout << " incorrect guesses left.\n";
            // Show recruit the letters he or she has guessed
            cout << "\nYou've used the following letters:\n" << used << endl;
            // Show player how much of the secret word he or she has guessed
            cout << "\nSo far, the word is:\n" << soFar << endl;
            
            // Display the simulation # is staring to the recruit.
            char guess;
            // Get recruit ’s guess
            cout << "\n\nEnter your guess: ";
            cin >> guess;
            // Making uppercase since keyword in uppercase
            guess = toupper(guess);
            // While recruit has entered a letter that he or she has already guessed
            while (used.find(guess) != string::npos)
            {
                cout << "\nYou've already guessed " << guess << endl;
                // Get recruit's next guess
                cout << "Enter Your guess: ";
                cin >> guess;
                guess = toupper(guess);
            }
            
            used += guess;
            if (THE_WORD.find(guess) != string::npos)
            {
                // Congratulate the recruit on guessing the secret words
                cout << "Congratulations " << guess << " is in the Keyword.\n";
                // Create an int var to count the number of simulations being run starting at 1
                // Pick new 3 random words from your collection as the secret code word the recruit has to guess.
                for (int i = 0; i < THE_WORD.length(); i++)
                {
                    // If the guess is in the secret word
                    if (THE_WORD[i] == guess)
                    {
                        // Update the word guessed so far with the new letter
                        soFar[i] = guess;
                    }
                }
            }
            // Otherwise
            else
            {
                // Tell the recruit the guess is incorrect
                cout << "Sorry, " << guess << " isn't in the word.\n";
                // Add the new guess to the group of used letters
                ++wrong;
            }
        }
        // Increment the number of simiulations ran counter
        // If the recruit has made too many incorrect guesses
        if (wrong == MAX_WRONG)
        {
            // Move program execution back up to // Display the simulation # is staring to the recruit.
            // Tell the recruit that he or she has failed the Keywords II course.
            cout << "\nYou've faild the program ";
        }
         // Otherwise
        else
        {
           // Tell the recruit the guess is correct
            cout << "\n You guessed it! ";
        }
        // Display End of Simulations to the recruit
        cout << "\nThe word was " << THE_WORD << endl;
        
        // Pause the Simulation with press any key to continue
        cout << "Press Enter to exit" << endl;
        string exitme;
        getline(cin, exitme);
        getline(cin, exitme);
        
        return 0;
        
    }

    
}
