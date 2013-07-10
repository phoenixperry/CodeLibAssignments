//
//  main.cpp
//  "Improved" Word Jumble
//
//  Created by Jen Taclas on 6/30/13.
//  Copyright (c) 2013 Jen Taclas. All rights reserved.
//

// Word Jumble (now with scoring!)
// The classic word jumble game where the player can ask for a hint

// Point value based on length of string. Deduct points for asking for hints.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    enum fields {WORD, HINT, NUM_FIELDS}; // Declare and initialize a 2-dimensional array with words and corresponding hints
    // The enumeration defines enumerators for accessing the array.
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."}
    };
    
	// PICKING A RANDOM WORD FROM THE CHOICES
    srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS); // Grabbing a random index based on the number of words in the array, which is 5. Then ——
    string theWord = WORDS[choice][WORD];  // theWord is now whatever rand() just grabbed
    string theHint = WORDS[choice][HINT];  // and the corresponding hint
    
    // PICKING A RANDOM LETTER AND THEN SWAPPING IN WITH ANOTHER RANDOM LETTER
    string jumble = theWord;  // Jumbled version of word created in the following block of code:
    int length = jumble.size(); // Calculating the number of slots in the string object/random word
    for (int i=0; i<length; ++i) // For each slot, do the following:
    {
        int index1 = (rand() % length); // Select a random slot in the string object. rand() can't be any number within length limit
        int index2 = (rand() % length); // Select another random slot in the string object, again, rand() limited to length
        char temp = jumble[index1]; // Assign the char 'temp' the value of the random letter (index1) from the random word (jumble)
        jumble[index1] = jumble[index2]; // The 1st random letter now reassigned the 2nd random letter's slot
        jumble[index2] = temp; // The 2nd random letter is reassigned to 'temp', which is saved as the original 1st letter before it swapped.
    }   // Now repeat that for however many times there are slots!
    
    // ATTEMPTING A SCORING SYSTEM
    int playerScore = 0;
    int plusScore = length * 10;
    
    // WELCOME TO DA THUNDADOME
    cout << "\t\t\tWelcome to Word Jumble!\n\n"; // Da fuq is '\t'? O WAIT IT'S TAB, ISN'T IT?? DOUBLE TAB. TAB THAT. TAB IT AGAIN. TABBY TAB
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";
    cout << "The jumble is: " << jumble << endl;
    cout << "This word will be worth " << plusScore << " points." << endl;
    
    string guess;
    cout << "\n\nYour guess: ";
    cin >> guess;
    
    while ((guess != theWord) && (guess != "quit"))
    {
        if (guess == "hint")
		{
            plusScore -= 10;
            cout << theHint << endl;
            cout << "The word is now worth " << plusScore << " points." << endl;
		}
        
        else
		{
            cout << "Sorry, that's not it.";
		}
        
        cout <<"\n\nYour guess: ";
        cin >> guess;
    }
    
    if (guess == theWord)
	{
        cout << "\nThat's it!  You guessed it!\n";
        playerScore = plusScore;
        cout << "Score is now " << playerScore << " ." << endl;
	}
    
    cout << "\nThanks for playing.\n";
    
    return 0;
}
