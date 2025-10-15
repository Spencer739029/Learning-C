#include <stdio.h>
#include <string.h>

int main() {
    int n = 0;
    // \/ Simple
    // while (n < 10) {
    //     n++;
    // }
    // \/ More complicated
    // while (1) {
    //     n++;
    //     if (n == 10) {
    //         break;
    //     }
    // }
    while (n < 10) {
        n++;

        /* check that n is odd */
        if (n % 2 == 1) {
            /* go back to the start of the while block */
            continue;
        }

        /* we reach this code only if n is even */
        printf("The number %d is even.\n", n);
    }

    int forLoop[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sumForLoop = 0;
    int i;

    for (i = 0; i < 10; i++) {
        sumForLoop += forLoop[i];
    }
    printf("Sum of array is %d\n", sumForLoop);


    char dest[20] = "Hello";
    char src[20] = "World";

    // Always calculate how much space is left in 'dest' before appending.
    // sizeof(dest) gives total buffer size (20 bytes)
    // strlen(dest) gives current string length (number of used bytes, excluding '\0')
    // Subtract 1 more for the null terminator.
    // This prevents buffer overflow and compiler warnings.
    strncat(dest, src, sizeof(dest) - strlen(dest) - 1);
    printf("%s\n", dest);

    // Repeat safely — the same formula keeps track of how much space is left now.
    strncat(dest, src, sizeof(dest) - strlen(dest) - 1);
    printf("%s\n", dest);

    // char * name = "John Smith"; Not manipulable
    char name[] = "John Smith"; // Can be name[11] to manually select length 
    // The reason that we need to add one, although the string John Smith is 
    // exactly 10 characters long, is for the string termination: 
    // a special character (equal to 0) which indicates the end of the string
    int age = 27;
    printf("%s is %d years old.\n", name, age);
    printf("Length of string is: %d\n",strlen(name)); // Use strlen to show string length

    if (strncmp(name, "John Smith", 11) == 0) { // Use strncmp to compare 2 strings
        printf("Hello John!\n");
    } else {
        printf("You're not John!\n");
    }

    int target = 10;
    int other = 10;
    int input = 6;
    if (input == target && target == other) {
        printf("Input & other is same as target\n");
    } else if (input < target) {
        printf("Input is smaller than target\n");
    } else if (input > target) {
        printf("input is bigger than target\n");
    } else {
        printf("Input invalid\n");
    }

    int array[][4] = {
        {0, 1, 2, 3} ,
        {4, 5, 6, 7} ,
        {8, 9, 10, 11}
    };
    // Could also be: int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    printf("Row 3, column 2: %d\n", array[2][1]);

    int numbers[10];

    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;
    numbers[5] = 60;
    numbers[6] = 70;
    printf("The 7th number in the array is %d\n", numbers[6]);

    int sum, a = 1, b = 2;
    sum = a + b;
    printf("Sum: %d", sum);
    return 0;
}
