#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void calculator();
void solveQuadratic();
void hub_calc()
{
    short choise_calc = 0;
    cout << "1.Basic calculator" << endl
         << "2.Discriminant" << endl;  
     
    cin >> choise_calc;
    system("cls || clear");
    switch(choise_calc){
        case 1:
        calculator();
        break;

        case 2:
        solveQuadratic();
        break;
    }

}
// Basic calculator function for simple operations
void calculator() 
{ 

    float a = 0, b = 0, res = 0;
    string operation;

    cout << "Enter the first number: ";
    cin >> a;

    cout << "Enter the action (+, -, *, /, // for square root, ** for power): ";
    cin >> operation;

    if (operation != "//") {
        cout << "Enter the second number: ";
        cin >> b;
    }

    if (operation == "+") {
        res = a + b;
        cout << res << endl;
    }
    else if (operation == "-") {
        res = a - b;
        cout << res << endl;
    }
    else if (operation == "*") {
        res = a * b;
        cout << res << endl;
    }
    else if (operation == "/") {
        if (b == 0) {
            cout << "Division by zero has been blocked by Pythagoras" << endl;
        }
        else {
            res = a / b;
            cout << res << endl;
        }
    }
    else if (operation == "//") {
        if (a < 0) {
            cout << "Cannot calculate square root of a negative number" << endl;
        }
        else {
            res = sqrt(a);
            cout << res << endl;
        }
    }
    else if (operation == "**") {
        res = pow(a, b);
        cout << res << endl;
    }
    else {
        cout << "Error expression!" << endl;
    }

    cout << endl << endl;
}

// Function to solve quadratic equations (ax² + bx + c = 0)
void solveQuadratic() 
{ 
    float a, b, c;
    cout << "Enter coefficient a: ";
    cin >> a;
    cout << "Enter coefficient b: ";
    cin >> b;
    cout << "Enter coefficient c: ";
    cin >> c;

    if (a == 0) {
        cout << "Coefficient 'a' cannot be zero in a quadratic equation." << endl;
        return;
    }

    // Calculate discriminant D = b² - 4ac
    float discriminant = b * b - 4 * a * c;
    cout << "Discriminant D = " << discriminant << endl;

    if (discriminant > 0) {
        float sqrtD = sqrt(discriminant);
        float x1 = (-b + sqrtD) / (2 * a);
        float x2 = (-b - sqrtD) / (2 * a);
        cout << "Two real roots:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (discriminant == 0) {
        float x = -b / (2 * a);
        cout << "One real root: x = " << x << endl;
    }
    else {
        cout << "No real roots. Complex roots exist." << endl;
    }

    cout << endl << endl;
}

