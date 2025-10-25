#include <iostream>
#include <cstdlib>  
#include <ctime>   

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int guess = -1;

    cout << "I have generated a random number between 1 and 100." << endl;
    cout << "Can you guess it?" << endl;

    // Loop until the user guesses the correct number
    while (guess != randomNumber) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number: " << randomNumber << endl;
        }
    }

    return 0;
}
