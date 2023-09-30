#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MIN = 1;
const int MAX = 100;

int guess;
int answer;
int lastGuess;

int randomNumber(int lower, int upper)
{
    srand(time(0));
    return (rand() % (upper - lower + 1)) + lower;
}

int isInteger(char input[])
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            return 0; // Not a valid integer
        }
    }
    return 1; // Valid integer
}

int main()
{
    answer = randomNumber(MIN, MAX);
    printf("Welcome to the Number Guessing Game!\n");

    do
    {
        char input[10]; // Buffer to store user input

        printf("Enter your guess (%d-%d): ", MIN, MAX);
        scanf("%s", input);

        // Check if the input is a valid integer
        if (!isInteger(input))
        {
            printf("Please enter a valid number between %d and %d.\n", MIN, MAX);
            continue;
        }

        guess = atoi(input); // Convert the valid input to an integer

        if (guess < answer)
        {
            printf("Guess higher!\n");
        }
        else if (guess > answer)
        {
            printf("Guess lower!\n");
        }

        lastGuess = guess;
    } while (guess != answer);

    printf("Congratulations! You guessed the correct number: %d\n", answer);

    return 0;
}
