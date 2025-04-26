#include <stdio.h>
#include <math.h>

double sqrts();
void calc()
{
    int ac;

    float a=0;
    float b=0;
    float res = 0;
    char var;

    printf("%s", "Enter the first number: ");
    scanf("%f",&a);
    // printf("%d\n", a);

    while((ac = getchar()) != '\n' && ac != EOF);   
    printf("%s", "Enter the action: ");
    scanf("%c",&var);
    
    // printf("%c\n", var);

    while((ac = getchar()) != '\n' && ac != EOF);   
    printf("%s", "Enter the second number: ");
    scanf("%f",&b);
    // printf("%d\n", b);

    switch (var)
    {
    case '+':
       res = a + b;
      printf("%.2f\n\n\n", res);
        break;
    case '-':
     res = a - b;
      printf("%.2f\n\n\n", res);
    break;
    case '*':
    res = a * b;
      printf("%.2f\n\n\n", res);
     break;
    case '/':
    res = a / b;
      if(b == 0){
        printf("%s\n\n\n", "Divide by zero has been blocked by Pythagoras");
        break;
      }else{

     
      printf("%.2f\n\n\n", res);
     break;
      }

        default:
        printf("%s\n", "Error expression!");
        break;
    }
}


double sqrts(){
  double a = 0;
  return sqrt(a);
}