#include "calc.h"
#include <stdio.h>

int calculate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b != 0)
                return a / b;
            else {
                printf("Error: divide by zero\n");
                return 0;
            }
        default:
            printf("Unknown operator\n");
            return 0;
    }
}
