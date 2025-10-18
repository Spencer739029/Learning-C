// structs_example.c
#include <stdio.h>
#include <string.h>

// A struct is a custom data type that groups multiple pieces of data together.
// Example: a "Person" with a name, age, and height.
struct Person {
    char name[50];
    int age;
    float height;
};

// A function that takes a struct by value (makes a copy)
void printPerson(struct Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Height: %.2f meters\n", p.height);
}

// A function that takes a pointer to a struct, so we can modify the original
void haveBirthday(struct Person *p) {
    p->age++;  // use '->' to access members through a pointer
    printf("Happy birthday, %s! You are now %d.\n", p->name, p->age);
}

// Example of a nested struct
struct Address {
    char city[50];
    char country[50];
};

struct Employee {
    struct Person info;      // nested struct
    struct Address location; // another nested struct
    int employeeID;
};

int main() {
    // Initialize a struct using designated initializers
    struct Person person1 = {"Alice", 30, 1.65f};
    printPerson(person1);

    haveBirthday(&person1);  // pass by reference (pointer)
    printPerson(person1);

    // Another way to assign struct members manually
    struct Person person2;
    strcpy(person2.name, "Bob");
    person2.age = 25;
    person2.height = 1.80f;

    printPerson(person2);

    // Create a nested struct (Employee)
    struct Employee emp = {
        {"Charlie", 40, 1.75f},        // Person info
        {"Sydney", "Australia"},       // Address info
        1001                           // Employee ID
    };

    printf("\nEmployee Info:\n");
    printf("Name: %s\n", emp.info.name);
    printf("Age: %d\n", emp.info.age);
    printf("City: %s\n", emp.location.city);
    printf("Country: %s\n", emp.location.country);
    printf("Employee ID: %d\n", emp.employeeID);

    return 0;
}
