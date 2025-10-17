#include <stdio.h>

int main() {
    int num = 10;            // a normal integer variable
    int *ptr = &num;         // a pointer to an int, storing the *address* of 'num'

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);   // %p prints a memory address
    printf("Pointer (ptr) holds: %p\n", ptr);
    printf("Value pointed to by ptr: %d\n", *ptr); // *ptr means “go to that address and get the value”

    // You can also modify the original variable through the pointer
    *ptr = 20;   // changes 'num' because ptr points to its memory
    printf("New value of num: %d\n", num);

    // Example with a function
    void changeValue(int *p);  // function prototype
    changeValue(&num);         // pass the address of 'num' (not its value)
    printf("After changeValue(), num = %d\n", num);

    return 0;
}

// Function that takes a pointer and modifies the original variable
void changeValue(int *p) {
    *p = 42;   // dereference the pointer and set its value
}
