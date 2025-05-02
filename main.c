#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calc.c"
#include "converter.c"
#include "random.c"
#include "Todo/todo.c"

int a = 0;
void choose()
{
 
    
    printf("%s\n", "Welcome to toolkit, choose the tool: ");
    printf("%s\n", "    1.Calculator (+, -, *, /, // for root, ** for power)");
    printf("%s\n", "    2.Converter (Distance, Weight, Temperature, Data, Password, Speed)");
    printf("%s\n", "    3.Random");
    printf("%s\n", "    4.Todo");
    printf("%s\n", "    0.Exit");
    scanf("%d",&a);

    switch(a){
        case 1:
            system("cls || clear");
            calc();
        break;
        case 2:
            system("cls || clear");
            hub();
        break;
        case 3:
            system("cls || clear");
            generate_yes_or_no();
        break;
        case 4:
            system("cls || clear");
            initialize_todo_system();
        break;
        case 0:
        system("exit");
        break;
    }
}

int main(int argc, char const *argv[])
{
    // start();


    choose();
    for(;;){
        if(a != 0){
            choose();
        }else{
            return 0;
        }
   }  
    return 0;
}
