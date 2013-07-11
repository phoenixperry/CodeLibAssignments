//
//  main.cpp
//  Homework3 (July 10, 2013)
//
//  Created by Cat on 7/10/13.
//  Copyright (c) 2013 Catt. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    vector<string> inventory;
    vector<string>::const_iterator iter;
    bool gameLoop = true; // set up a game loop
    string gameItem;
    string yesNo;
    int turnCount = 0;

    cout << "You are the new companion! You are going on a trip with Dr. Who. You can take up to 10 times with you in this suitcase that can hold any item of any size.\n";
    
    while(gameLoop) {
    cout << "\nWhat would you like to add to your inventory?\n";
     cin >> gameItem;
     inventory.push_back(gameItem);
        
        cout << "\nYour Items:" << endl;
        
        for(iter = inventory.begin(); iter != inventory.end(); ++iter) {
            cout << *iter << "\n";
        }
        
        cout << "\nDo you wish to remove any item? (yes/no)" << endl;
        cin >> yesNo;
        if (yesNo == "yes") {
            cout << "\nWhat would you like to remove?" << endl;
            string removeItem;
            cin >> removeItem;
            iter = find(inventory.begin(), inventory.end(), removeItem);
            
            if (iter != inventory.end()){
                inventory.erase(iter);
                cout << removeItem << " has been removed." << endl;
                cout << "\nYour Items:" << endl;
                
                for(iter = inventory.begin(); iter != inventory.end(); ++iter) {
                    cout << *iter << "\n";
                }
            }
        }
        
        turnCount++;
        if (turnCount == 10) {
            gameLoop = false;
        }

    }
    return 0;
}

