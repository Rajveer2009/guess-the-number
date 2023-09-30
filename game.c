#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MIN = 1;
const int MAX = 100;

int guess;
int answer;
int lastGuess;

// Function to generate a random number within a given range
int randomNumber(int lower, int upper) {
    srand(time(0));
    int number = (rand() % (upper - lower + 1)) + lower;
    return number;
}

int main() {
    // Generate a random answer within the specified range
    answer = randomNumber(MIN, MAX);

    printf("Welcome to the Number Guessing Game!\n");

    // Game loop
    do {

        printf("Enter your guess (%d-%d): ", MIN, MAX);
        scanf("%d", &guess);

        // Check if the guess is out of range and promt for a new guess
        if (guess < MIN || guess > MAX) {
            printf("Please enter a number between %d and %d.\n", MIN, MAX);
        }

        // Provide hints based on the guess
        if (guess < answer) {
            printf("Guess higher!\n");
        }
        else if (guess > answer) {
            printf("Guess lower!\n");
        }

        lastGuess = guess;
    } while (guess != answer);

    // You've guessed the correct number
    printf("Congratulations! You guessed the correct number: %d\n", answer);

    return 0;
}