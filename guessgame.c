#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main() {
    srand(time(NULL));

    int guess;
    int random_number;
    char restart[10];
    
    while (1) {
        random_number = rand() % 100 + 1;
        printf("I have number in mind from 1-100!\nTry to guess it!");
        while (1) {
            printf("\nEnter guess: ");
            scanf("%i", &guess);

            if (guess > 100 || guess < 1) {
                printf("Number has to be 1-100!\n");
            } else if (guess == random_number) {
                printf("You guessed it!\n");
                break;
            } else if (guess > random_number) {
                printf("Guess too big!");
            } else if (guess < random_number) {
                printf("Guess too small!");
            }
        }

        printf("Restart or exit?\n");
        scanf("%9s", restart);
        char lower_restart[20];
        for (int i = 0; restart[i]; i++) {
            lower_restart[i] = tolower((unsigned char)restart[i]);
        }
        lower_restart[strlen(restart)] = '\0';

        if (strcmp(lower_restart, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else if (strcmp(lower_restart, "restart") == 0) {
            continue;
        } else {
            printf("Invalid option! try again!\n");
            printf("Restart or exit?");
            scanf("%9s", &restart);
        }
    }
    return 0;
}