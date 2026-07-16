#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(static_cast<unsigned int>(time(0)));

    int targetNumber = rand() % 100 + 1;

    int userGuess = 0;
    int attempts = 0;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "I have selected a random number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess > targetNumber) {
            cout << "Your guess is too high. Try again." << endl;
        } else if (userGuess < targetNumber) {
            cout << "Your guess is too low. Try again." << endl;
        }

        attempts++;
    } while (userGuess != targetNumber);
    cout << "Congratulations! You guessed the correct number: " << targetNumber << endl;
    cout << "It took you " << attempts << " attempts." << endl;

    return 0;
}
