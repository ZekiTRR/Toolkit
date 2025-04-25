#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calc.c"
#include "converter.c"

int a = 0;
void choose()
{
    printf("%s\n", "Welcome to toolkit, choose the tool: ");
    printf("%s\n", "    1.Calculator");
    printf("%s\n", "    2.Converter (Distance)");
    printf("%s\n", "    0.Exit");
    scanf("%d",&a);
    // printf("%s\n", "Welcome to toolkit, choose the tool: ");

    // printf("%s\n", "Welcome to toolkit, choose the tool: ");

    switch(a){
        case 1:
            system("cls");
            calc();
        break;
        case 2:
            system("cls");
            distance_converter();
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
