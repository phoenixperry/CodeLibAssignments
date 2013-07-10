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
    cout << "You are the new companion! You are going on a trip with Dr. Who. You can take up to 10 times with you in this suitcase that can hold any item of any size. What would you like to add?\n";
    vector<string> inventory;
    vector<string>::const_iterator iter;
    
    bool gameLoop = true; // set up a game loop
    
    while(gameLoop) {
        string gameItem;
        cin >> gameItem;
        inventory.push_back(gameItem);
        cout << "Your Items:" << endl;
        for(iter = inventory.begin(); iter != inventory.end(); ++iter) {
            cout << *iter << endl;
        }
        cout << "Do you wish to remove any item? (yes/no)" << endl;
        string yesNo;
        cin >> yesNo;
        if (yesNo == "yes") {
            cout << "What would you like to remove?" << endl;
            string removeItem;
            cin >> removeItem;
            iter = find(inventory.begin(), inventory.end(), removeItem);
            if (iter != inventory.end()){
                var removeItemPosition = iter.size();
                inventory.pop_back(removeItemPosition);
                cout << removeItem << " has been removed." << endl;
            }
        }
        int turnCount = 0;
        turnCount++;
        if (turnCount == 10) {
            gameLoop = false;
        }
    }
    return 0;
}

