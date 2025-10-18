#include <stdio.h>
#include <string.h>

// 'static' before a function limits its visibility to this file (like "private" in other languages)
static void func(void) {
    printf("I am a static function.\n");
}

// Uses a static local variable that keeps its value between calls
int runner() {
    static int count = 0;  // persists across function calls
    count++;
    return count;
}

int fun(int bar);

// Basic struct definition
struct point {
    int structx;
    int structy;
};

// main = program entry point
int main() {
    int structx = 10;
    int structy = 5;
    // Fixed: use %d for integers
    printf("X = %d, Y = %d\n", structx, structy);

    int number = 1;
    int *pointer_to_number = &number;  // pointer holds the address of number

    printf("Value of number: %d\n", number);
    printf("Value via pointer: %d\n", *pointer_to_number);  // dereference pointer

    func();  // Call static function

    // Demonstrate static variable persistence
    printf("Runner %d\n", runner());
    printf("Runner %d\n", runner());

    fun(1);

    int n = 0;
    while (n < 10) {
        n++;

        if (n % 2 == 1)  // skip odd numbers
            continue;

        printf("%d is even.\n", n);
    }

    // Basic for loop sum example
    int forLoop[10] = {1,2,3,4,5,6,7,8,9,10};
    int sumForLoop = 0;
    for (int i = 0; i < 10; i++)
        sumForLoop += forLoop[i];
    printf("Sum of array = %d\n", sumForLoop);

    // Safe string concatenation
    char dest[20] = "Hello";
    char src[20] = "World";
    strncat(dest, src, sizeof(dest) - strlen(dest) - 1);
    printf("%s\n", dest);
    strncat(dest, src, sizeof(dest) - strlen(dest) - 1);
    printf("%s\n", dest);

    // String example
    char name[] = "John Smith"; // modifiable string
    int age = 27;
    printf("%s is %d years old.\n", name, age);
    printf("Length: %zu\n", strlen(name));

    if (strncmp(name, "John Smith", 11) == 0)
        printf("Hello John!\n");
    else
        printf("You're not John!\n");

    // Conditional logic
    int target = 10, other = 10, input = 6;
    if (input == target && target == other)
        printf("Input & other match target\n");
    else if (input < target)
        printf("Input < target\n");
    else if (input > target)
        printf("Input > target\n");
    else
        printf("Invalid input\n");

    // 2D array access
    int array[][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    printf("Row 3, Col 2: %d\n", array[2][1]);

    // Basic array
    int numbers[10] = {10,20,30,40,50,60,70};
    printf("7th number = %d\n", numbers[6]);

    int a = 1, b = 2, sum = a + b;
    printf("Sum = %d\n", sum);

    return 0;
}

int fun(int bar) {
    printf("Function test\n");
    return bar * 2;
}
