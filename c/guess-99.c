//
// Guess a Number - Example in C(99)
//
// Compile: gcc -o guess guess-99.c
// Run: ./guess
//

#include <stdio.h> // this is required for printf()
#include <stdlib.h> // this is required for rand()
#include <math.h> // this is required for ceil()
#include <time.h> // this is required for time()

int main() {

    // Initialize random number generator
    // note: in c you have to initialize your rng, otherwise the results of rand()
    // are predictable. This initialization here is far from perfect. It changes every
    // second only. If you start the game more than once in a second you will get
    // the same results.
    srand(time(0));

    int min = 1;
    int max = 100;
    int randomNumber = rand() % (max - min + 1) + min;
    int currentGuess = max / 2;
    int lastMin = 0;
    int lastMax = max;
    _Bool solved = 0;
    int numberOfGuesses = 0;

    while (!solved) {
        numberOfGuesses++;
        if (randomNumber > currentGuess) {
            lastMin = currentGuess;
            printf("The number to guess is greater than %d\n", currentGuess);
            currentGuess = currentGuess + (int) (ceil(abs(lastMax - currentGuess) / 2));
        } else if (randomNumber < currentGuess) {
            lastMax = currentGuess;
            printf("The number to guess is less than %d\n", currentGuess);
            currentGuess = currentGuess - (int) (ceil(abs(lastMin - currentGuess) / 2));
        } else {
            printf("The number to guess was %d\n", randomNumber);
            printf("You won!");
            solved = 1;
        }

    }
    printf("That was a fun game! It needed %d guesses\n", numberOfGuesses);
    return 0;
}

