#include <stdio.h>
#include <math.h>
#include <string.h>

void calc()
{
    int ac;
    float a = 0;
    float b = 0;
    float res = 0;
    char operation[3];

    printf("%s", "Enter the first number: ");
    scanf("%f", &a);

    while((ac = getchar()) != '\n' && ac != EOF);   
    printf("%s", "Enter the action (+, -, *, /, // for square root, ** for power): ");
    scanf("%2s", operation); 

    // ROOT != second number
    if (strcmp(operation, "//") != 0) {
        while((ac = getchar()) != '\n' && ac != EOF);   
        printf("%s", "Enter the second number: ");
        scanf("%f", &b);
    }

    if (strcmp(operation, "+") == 0) {
        res = a + b;
        printf("%.2f\n\n\n", res);
    }
    else if (strcmp(operation, "-") == 0) {
        res = a - b;
        printf("%.2f\n\n\n", res);
    }
    else if (strcmp(operation, "*") == 0) {
        res = a * b;
        printf("%.2f\n\n\n", res);
    }
    else if (strcmp(operation, "/") == 0) {
        if(b == 0) {
            printf("%s\n\n\n", "Division by zero has been blocked by Pythagoras");
        } else {
            res = a / b;
            printf("%.2f\n\n\n", res);
        }
    }
    else if (strcmp(operation, "//") == 0) {
        if (a < 0) {
            printf("%s\n\n\n", "Cannot calculate square root of a negative number");
        } else {
            res = sqrt(a); // Квадратный корень из a
            printf("%.2f\n\n\n", res);
        }
    }
    else if (strcmp(operation, "**") == 0) {
        res = pow(a, b); // a в степени b
        printf("%.2f\n\n\n", res);
    }
    else {
        printf("%s\n", "Error expression!");
    }
}