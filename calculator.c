#include <stdio.h>
#include <ctype.h>

int main() {
    float num1;
    float num2;
    char operation;
    float sum;
    char remainder_ask;
    int remainder;

    printf("Enter num 1: ");
    scanf("%f", &num1);
    printf("Enter num 2: ");
    scanf("%f", &num2);
    printf("Enter an operation (+, -, *, /): ");
    scanf(" %c", &operation); // Space before %c to consume any leftover newline

    if (operation == '+') {
        sum = num1 + num2;
        printf("Sum: %.1f\n", sum);
    } else if (operation == '-') {
        sum = num1 - num2;
        printf("Sum: %.1f\n", sum);
    } else if (operation == '*') {
        sum = num1 * num2;
        printf("Sum: %.1f\n", sum);
    } else if (operation == '/') {
        if (num2 == 0.0) {
            printf("Cannot divide by 0!");
        } else {
            sum = num1 / num2;
            printf("Sum: %.1f\n", sum);
            printf("Get remainder? (y/n)");
            scanf(" %c", &remainder_ask);
            if (tolower(remainder_ask) == 'y') {
                remainder = (int)num1 % (int)num2;
                printf("Remainder: %d\n", remainder);
            }
        }
    }
}