//
//  main.cpp
//  Homework2 (July 3 2013)
//
//  Created by Cat on 7/3/13.
//  Copyright (c) 2013 Catt. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"wall","Do you feel you're banging your head against something?"},
        {"glasses","Johnny Bravo can't be seen without them."},
        {"labored","Going slowly, is it?"},
        {"persistent","Keep at it."},
        {"jumble","It's like jam, when you mumble."}
    };
    
    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand()%NUM_WORDS);
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];
    
    string jumble = theWord;
    int length = jumble.size();
    
    for (int i = 0; i < length; ++i)
    {
        int index1 = (rand()%length);
        int index2 = (rand()%length);
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }
    
    cout << "\t\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";
    cout << "The jumble is:" << jumble;
    
    string guess;
    cout << "\n\n Your guess: ";
    cin >> guess;
    
    int score = 0;
   while ((guess!=theWord)&&(guess != "quit")) {
        
        if (guess == "hint") {
            cout << theHint;
            score--;
            cout << "\nYour score:" << score;
       }
              
        else {
            cout << "Sorry, that's not it.";
        }
        cout << "The jumble is:" << jumble;   
        cout << "\n\n Your guess: ";
        cin >> guess;
        
    }
    if (guess == theWord) {
        cout << "\nThat's it! You guessed it!\n";
        score = score + length;
        cout << "Your score:" << score;

    }
    cout << "\nThanks for playing!\n";

}

