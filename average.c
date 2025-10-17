#include <stdio.h>

int main() {
    int numbers[2];
    int average;

    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;

    average = (numbers[0] + numbers[1] + numbers[2]) / 3;

    printf("The average is %d", average);
    return 0;
}