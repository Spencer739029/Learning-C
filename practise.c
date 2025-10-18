#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure representing a person with a name and age
typedef struct {
    char * name;
    int age;
} person;

// Increments an integer by reference (modifies the original value)
// Parameter: argument - pointer to the integer to increment
void addone(int *argument) {
    // Dereference the pointer and increment the value at that memory address
    // This modifies the original variable passed by the caller
    (*argument)++;
}

// Static function - only visible within this file (internal linkage)
// Equivalent to "private" visibility in other languages
static void func(void) {
    printf("I am a static function.\n");
}

// Demonstrates static local variable that retains its value between function calls
// Returns: The number of times this function has been called
int runner() {
    // Static variable initialized once and persists across all function calls
    static int count = 0;
    count++;
    return count;
}

// Forward declaration of fun() to allow calling it before its definition
int fun(int bar);

// Structure definition for a 2D point with x and y coordinates
struct point {
    int structx;
    int structy;
};

// Main function - entry point of the program
int main() {
    // Dynamically allocate memory for a person struct on the heap
    // Cast malloc's void* return to person* for type safety
    person * myperson = (person *) malloc(sizeof(person));

    // Demonstrate pass-by-reference with pointers
    int argument;
    printf("Before: %d\n", argument);
    addone(&argument);  // Pass address of argument to modify it
    printf("After: %d\n", argument);

    // Simple coordinate variables
    int structx = 10;
    int structy = 5;
    
    printf("X = %d, Y = %d\n", structx, structy);

    // Pointer demonstration: storing and accessing memory addresses
    int number = 1;
    int *pointer_to_number = &number;  // Store address of number

    printf("Value of number: %d\n", number);
    printf("Value via pointer: %d\n", *pointer_to_number);  // Dereference to get value

    // Call the static function defined earlier
    func();

    // Demonstrate that static variables persist across function calls
    printf("Runner %d\n", runner());  // Prints 1
    printf("Runner %d\n", runner());  // Prints 2

    fun(1);

    // While loop with continue statement to skip odd numbers
    int n = 0;
    while (n < 10) {
        n++;

        if (n % 2 == 1)  // Skip to next iteration if n is odd
            continue;

        printf("%d is even.\n", n);
    }

    // For loop example: calculate sum of array elements
    int forLoop[10] = {1,2,3,4,5,6,7,8,9,10};
    int sumForLoop = 0;
    for (int i = 0; i < 10; i++)
        sumForLoop += forLoop[i];
    printf("Sum of array = %d\n", sumForLoop);

    // Safe string concatenation using strncat to prevent buffer overflow
    char dest[20] = "Hello";
    char src[20] = "World";
    // Concatenate src to dest, limiting bytes to prevent overflow
    strncat(dest, src, sizeof(dest) - strlen(dest) - 1);
    printf("%s\n", dest);
    strncat(dest, src, sizeof(dest) - strlen(dest) - 1);
    printf("%s\n", dest);

    // String manipulation and comparison examples
    char name[] = "John Smith"; // Stack-allocated, modifiable character array
    int age = 27;
    printf("%s is %d years old.\n", name, age);
    printf("Length: %zu\n", strlen(name));  // %zu is for size_t type

    // Safe string comparison using strncmp (compares first n characters)
    if (strncmp(name, "John Smith", 11) == 0)
        printf("Hello John!\n");
    else
        printf("You're not John!\n");

    // Conditional branching with multiple conditions
    int target = 10, other = 10, input = 6;
    if (input == target && target == other)
        printf("Input & other match target\n");
    else if (input < target)
        printf("Input < target\n");
    else if (input > target)
        printf("Input > target\n");
    else
        printf("Invalid input\n");

    // 2D array declaration and access
    int array[][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    printf("Row 3, Col 2: %d\n", array[2][1]);  // Arrays are zero-indexed

    // 1D array declaration with partial initialization
    // Uninitialized elements default to 0
    int numbers[10] = {10,20,30,40,50,60,70};
    printf("7th number = %d\n", numbers[6]);  // Access 7th element (index 6)

    // Basic arithmetic and variable declaration
    int a = 1, b = 2, sum = a + b;
    printf("Sum = %d\n", sum);

    // Note: myperson is never freed - memory leak!
    // Should call: free(myperson);
    free(myperson);
    // Now no memory leakage
    
    return 0;  // Return 0 to indicate successful execution
}

// Simple function that doubles its input
// Parameter: bar - integer to be doubled
// Returns: bar multiplied by 2
int fun(int bar) {
    printf("Function test\n");
    return bar * 2;
}