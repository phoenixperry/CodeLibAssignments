//
//  main.cpp
//  Homework1 (June 19 2013)
//
//  Created by Cat on 6/20/13.
//  Copyright (c) 2013 Catt. All rights reserved.
//

#include <iostream> // Pre-processor
#include <string>
using namespace std;

int main() {
    cout << "What's your name?" << endl;
    string name;
    cin >> name;
    cout << "Is " + name + " correct?" << endl;
    string nameTof;
    cin >> nameTof;
    
    if ( nameTof == "no" ) { // single = assigns a value. == compares values
        cout << "So what is your name?" << endl;
        cin >> name;
        cout << "Well, " << name << ", let's move on!\n" << endl;
    }
    else if ( nameTof == "yes" ) {
        cout << "Well, " << name << ", let's move on!\n" << endl;
    }
    
    else {cout << "I'm going to assume that means yes!\n" << endl;}
    
    cout << "What's the name of your rival?" << endl;
    string rivalName;
    cin >> rivalName;
    cout << rivalName << ", huh? Well, " << rivalName << " is angry and wants to fight. " << rivalName << " decided to let you go first.\n" << endl;

    int myHealth = 100;
    int rivalHealth = 100;

    string attackDefend;
    bool gameLoop = true; // set up a game loop

    while(gameLoop) {
        
        if (myHealth != 0) {
            cout << "It's your turn, " << name << "! What do you do?\n(attack/defend)" << endl;
            cin >> attackDefend;
            if ( attackDefend == "attack" ) {
                rivalHealth -= 10;
                cout << "You attacked. Your HP is " << myHealth << "% full. " << rivalName << "'s HP is " << rivalHealth << "% full.\n" << endl;
            }
            else {
                myHealth -= 5;
                cout << "You defended. Your HP is " << myHealth << "% full. " << rivalName << "'s HP is " << rivalHealth << "% full.\n" << endl;
            }

            cout << rivalName << " is about to attack! What do you do?\n(attack/defend)" << endl;
            cin >> attackDefend;
            if ( attackDefend == "attack" ) {
                rivalHealth -= 10; //subtract in an increment of 10 before anything else happens
                myHealth -= 10;
                cout << "You attacked. Your HP is " << myHealth << "% full. " << rivalName << "'s HP is " << rivalHealth << "% full.\n" << endl;
            }
            else {
                myHealth -= 5;
                cout << "You defended. Your HP is " << myHealth << "% full. " << rivalName << "'s HP is " << rivalHealth << "% full.\n" << endl;
            }
        }
        
        if (myHealth == 0) {
            cout << name << ", I'm sorry to say you were defeated by " << rivalName << ". Your family will be shamed for your loss!" << endl;
            gameLoop = false; // end game state
        }
        else if (rivalHealth == 0) {
            cout << name << ", good job! You defeated " << rivalName << " and took all their money. Their family will now live in shame and poverty!" << endl;
            gameLoop = false; // end game state
        }

    }
}
