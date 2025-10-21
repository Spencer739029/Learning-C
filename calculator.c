#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main() {
    float num1, num2, sum;
    char operation[10];
    char remainder_ask;
    char rounding[9];
    char upordown[9];
    char again[5];

    while (1) {
        printf("\nEnter num 1: ");
        scanf("%f", &num1);

        printf("Options: +, -, *, /, pow, sqrt\n");
        printf("Enter an operation: ");
        scanf("%9s", operation);

        if (strcmp(operation, "sqrt") != 0) {
            printf("Enter num 2: ");
            scanf("%f", &num2);
        } else {
            num2 = 0;
        }

        if (strcmp(operation, "+") == 0) {
            sum = num1 + num2;
            printf("Sum: %.2f\n", sum);

        } else if (strcmp(operation, "-") == 0) {
            sum = num1 - num2;
            printf("Sum: %.2f\n", sum);

        } else if (strcmp(operation, "*") == 0) {
            sum = num1 * num2;
            printf("Sum: %.2f\n", sum);

        } else if (strcmp(operation, "/") == 0) {
            if (num2 == 0.0) {
                printf("Cannot divide by 0!\n");
                continue;
            }
            sum = num1 / num2;
            printf("Sum: %.2f\n", sum);

            printf("Get remainder? (y/n): ");
            scanf(" %c", &remainder_ask);
            if (tolower(remainder_ask) == 'y') {
                int remainder = (int)num1 % (int)num2;
                printf("Remainder: %d\n", remainder);
            }

        } else if (strcmp(operation, "pow") == 0) {
            sum = pow(num1, num2);
            printf("Power: %.2f\n", sum);

        } else if (strcmp(operation, "sqrt") == 0) {
            if (num1 < 0) {
                printf("Cannot take square root of a negative number!\n");
                continue;
            }
            sum = sqrt(num1);
            printf("Square root: %.2f\n", sum);

        } else {
            printf("Invalid operation!\n");
            continue;
        }


        printf("Round result? (y/n): ");
        scanf("%9s", rounding);

        if (tolower(rounding[0]) == 'y') {
            printf("Up or down? (u/d): ");
            scanf("%9s", upordown);

            if (tolower(upordown[0]) == 'u') {
                sum = ceil(sum);
                printf("Rounded up: %.1f\n", sum);
            } else if (tolower(upordown[0]) == 'd') {
                sum = floor(sum);
                printf("Rounded down: %.1f\n", sum);
            } else {
                printf("Invalid rounding option.\n");
            }
        }
        

        printf("\nDo another calculation? (y/n): ");
        scanf("%4s", again);
        if (tolower(again[0]) != 'y') {
            printf("Goodbye!\n");
            break;
        }
    }

    return 0;
}
