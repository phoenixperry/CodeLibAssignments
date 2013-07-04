//
//  By Ida for Laine

#include <iostream>
using namespace std;

int Ida = 100;
int Laine = 100;
string playerInput = " ";

bool gameLoop = true;

int main(int argc, const char * argv[]) {
    cout << endl << "Laine is coming! Hug, kiss or compliment?" << endl;
    while (gameLoop) {
        
        if (Ida != 0) {
            
            cin >> playerInput;
        }
        
        if (playerInput == "hug") {
            Laine += 20;
            Ida += 10;
            cout << endl << "Damn, you're cute! Score is now: \nIda: "<< Ida << ", Laine:" << Laine;
            
        }
        else if (playerInput == "kiss") {
            Ida += 40;
            Laine += 20;
            cout << endl << "Mmmm... Score is now: \nIda: " << Ida << ", Laine:" << Laine;
        }
        
        else if (playerInput == "compliment"){
            Ida += 20;
            Laine += 50;
            cout << endl << "Love wins! The score is now: \nIda: " << Ida << ", Laine:" << Laine;
        }
        
        cout << endl << "\nDon't stop now! Hug, kiss or compliment?" << endl;
        
        if (Laine == 500) {
            cout << endl << "Love wins! BAGILLIONS OF POINTS" << endl << "Play again?";
            
        }
        
    }
    
    
}
