#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: calc <num1> <op> <num2>\n");
        return 1;
    }

    int a = atoi(argv[1]);        // Convertit le premier argument en entier
    int b = atoi(argv[3]);        // Convertit le troisième argument en entier
    char op = argv[2][0];         // Récupère l'opérateur (+, -, *, /)

    switch (op) {
        case '+': printf("%d\n", a + b); break;
        case '-': printf("%d\n", a - b); break;
        case '*': printf("%d\n", a * b); break;
        case '/':
            if (b != 0)
                printf("%d\n", a / b);
            else
                printf("Error: divide by zero\n");
            break;
        default:
            printf("Unknown operator\n");
    }

    return 0;
}
