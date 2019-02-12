#include <iostream>
using namespace std;

int main(){

    int correctGuess = 15;
    int guess;
    bool won = false;

    while (!won){
        cout << "Enter your guess >> ";
        cin >> guess;
       if (guess == correctGuess) { 
            cout << "Your guess of " << guess << " is correct!";
            won = true;
        } else {
            cout << "Try again!" << endl;
        }
    }
}
