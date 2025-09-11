// Sample program for the free course on examining PE file structures

#include <stdio.h>
#include <stdlib.h>

// Function declarations
void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void print_result(int a, int b, char op, int result);



int main(int argc, char* argv[]) {

    // Check if correct number of arguments are provided
    if (argc != 4) {
        printf("Usage: %s num1 operator num2\n", argv[0]);
        return 1;
    }

    // Convert string arguments to appropriate types
    int num1 = atoi(argv[1]);
    char oper = argv[2][0];
    int num2 = atoi(argv[3]);

    // Call appropriate function based on oper
    switch (oper) {
    case '+':
        add(num1, num2);
        break;
    case '-':
        subtract(num1, num2);
        break;
    case '*':
        multiply(num1, num2);
        break;
    default:
        printf("Invalid operator! Use +, -, or *\n");
        return 1;
    }

    return 0;
}

// Addition function
void add(int a, int b) {
    int result = a + b;
    print_result(a, b, '+', result);
}

// Subtraction function
void subtract(int a, int b) {
    int result = a - b;
    print_result(a, b, '-', result);
}

// Multiplication function
void multiply(int a, int b) {
    int result = a * b;
    print_result(a, b, '*', result);
}

// Print result function
void print_result(int a, int b, char op, int result) {
    printf("%d %c %d = %d\n", a, op, b, result);
}