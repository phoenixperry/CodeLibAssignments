//
//  main.cpp
//  It's Bigger On The Inside
//
//  Created by Jen Taclas on 7/4/13.
//  Copyright (c) 2013 Jen Taclas. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool gameLoop = true;
int turns = 10;
int numItems = 1;

int main()
{
    const int MAX_ITEMS = 10;
    string suitcase[MAX_ITEMS] = {"wedding dress"}; // Declaring my array. The size of my suitcase is limited to 10 items.
    
    
    // WELCOME
    cout << "You are about to join the Doctor for a year on the Tardis. This may not end well for you. Very sorry . . .\n" << endl;
    cout << "But good news! You have a Bag of Holding in the latest style!: SUITCASE. Oooh, how modern!\n" << endl;
    cout << "You can only bring 10 items, though, but those items can be ANY size. Neato! So — what'll it be?" << endl;
    
    cout << "\nYou currently have in your suitcase: " << endl;
    for (int i = 0; i < numItems; ++i)
    {
        cout << "\t- " << suitcase[i] << endl;
    }
    
    if (numItems == 0)
    {
        cout << "\tnothing" << endl;
    }
        
    
    
    // TURN 0
    string item1 = " ";
    
    cout << endl << "Is there anything you want to remove?";
    cout << " (Type your selection below. If there isn't anything you wish to remove, type 'no')" << endl;
    
    // Player will now enter some text. Program must recognize if the selection input matches any elements in my index
    cin >> item1;
       
    if (suitcase[0].find(item1) != string::npos) // It matches element in slot 0
    {
        cout << "You removed " << item1 << " from your suitcase." << endl;
        item1.erase();
        numItems--;
    }
    else if (item1 == "no")
    {
        cout << "Very well then." << endl;
    }

    // END OF TURN 0
    
    
    // TURN LOOP
    while (gameLoop)
    {
        // Inventory update
        cout << "\nYou have " << turns << " turns to make your remaining selections." << endl;
        cout << "You currently have in your suitcase: " << endl;
        for (int i = 0; i < numItems; ++i)
        {
            cout << "\t- " << suitcase[i] << endl;
        }
        
        if (numItems == 0)
        {
            cout << "\tnothing" << endl;
        }

        // Add an item
        string addItem = " ";
        cout << "What else would you like to pack? Enter it below." << endl;
        cin >> addItem;
        
        if (numItems < MAX_ITEMS) // If you still have room in your inventory, also called 'bounds checking'
        {
            suitcase[numItems++] = addItem; // Add item to you inventory
        }
        else // if you DON'T have room in your inventory
        {
            cout << "You have too much baggage and can't close the zipper." << endl;
        }
        
        // Remove an item
        string removeItem = " ";
        cout << "Is there anything you want to leave behind? Enter it below." << endl;
        cin >> removeItem;
        for (int i = 0; i < MAX_ITEMS; ++i)
        {
            if (suitcase[i].find(removeItem) != string::npos) // It matches element in slot 0
            {
                cout << "You removed " << removeItem << " from your suitcase." << endl;
                removeItem.erase();
                numItems--;
            }
            else if (removeItem == "no")
            {
                cout << "Very well then." << endl;
            }
        }
        turns -= 1;
        
        //Let's end this!
        if (turns == 0)
        {
            cout << "Excellent! I think you're ready. The Doctor had to check on a problem with the Tardis. Now, if you'll just wait outside with your suitcase, he'll be right with you in 5 minutes." << endl;
            cout << "\nEPILOGUE\nHe never came back." << endl;
            gameLoop = false;
        }

    }
    
    gameLoop = false;
    
    return 0;
}

