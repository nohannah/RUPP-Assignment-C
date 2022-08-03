#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
//int main() {
    // char chr='b';
    // int age =19;
    // const float PI=3.14;

    // printf("Character=%c\n",chr);
    // printf ("Age =%d\n",age);
    // printf("PI=%f",PI);
    // return 0;
    // char chr;
    // printf("Enter the letter:");
    // scanf("%c",&chr);
    // printf("you enter %c",chr);
    // return 0;
    // int a;
    // float b;
    // printf ("Enter an interger and then a float:");
    // scanf ("%d%f",&a,&b);
    // printf("you enteres %d and %g", a,b);
    // int a =10,b=18;
    // printf("a+b %d\n", a+b );
    // printf("a-b %d\n", a-b );
    // printf("a*b %d\n", a*b );
    // printf("a/b %d\n", a/b );
    // printf("ab %d\n", a%b );
    // int R=20;
    // float A=pow(A,2)*M_PI;
    // printf("A=%.2f cm2",A);
    //  return 0;}
//Ex: 5

// #include <stdio.h>
// #include <math.h>
//  int main()
//  {
//   int Old_population= 312032486;
//   int Born = (3600/6) * 24* 365;
//   int Death= (3600/15)* 24 *365;
//   int Immigrant= (3600/45)* 24 *365;
//   int population= (Born + Immigrant - Death)*5 + Old_population;
//   printf(" population=%d",population);
//   return 0;
  
// }

//7. 

#include <stdio.h>
int main()
{
int A, B, sum = 0;
 // Ask user to enter the two numbers 
    printf("Enter two numbers A and B : \n");
 // Read two numbers from the user || A = 2, B = 3
    scanf("%d%d", &A, &B);
  
// Calculate the addition of A and B
    // using '+' operator
    sum = A + B;
    // Print the sum
    printf("Sum of A and B is: %d", sum);
     
    return 0;
}
  //8. 
#include <stdio.h>
#include <math.h>
// Ask user to enter the weight in kilogram 
int main(){
  // 1 kilogram = 2.204 pound
  float Weight_in_kilogram;
  printf(" Enter your weight: \n");
  scanf("%f",&Weight_in_kilogram );
  float Weight= Weight_in_kilogram * 2.204;
  printf("Weight=%.2f kilogram", Weight);

  return 0;
}
//9. 
#include <stdio.h>
#define _USE_MATH_DEFINE
#include <math.h>
int main(){
  // Enter radius and lenght
  float radius;
  float lenght;
  printf("Enter the radius: \n");
  scanf("%f",&radius);
  printf("Enter the lenght: \n");
  scanf("%f",&lenght);
  float area= pow(radius,2)* M_PI; 
  float volume= area * lenght;
  printf("volume=%.2f",volume);
  return 0;
}
//6
#include <stdio.h>
int main(){
  int num1,num2,temp;
  printf("Enter value of num1: \n");
  scanf("%d",&num1);
  printf("Enter value of num2: \n");
  scanf("%d",&num1);
  temp=num1;
  num1=num2;
  num2=temp;
  printf("After Swapping: num1= %d, num2 = %d", num1, num2);
  return 0;
}
//10. 
#include <stdio.h>
#include <math.h>
// Ask user to enter the input
int main(){
  float InitialTemperature;// in degrees Celsius
  float FinalTemperature;// in degrees Celsius
  float M;//weight of water in kilogram
  printf("Enter the InitialTemperature: \n");
  scanf("%f",&InitialTemperature);
  printf("Enter the FinalTemperature: \n");
  scanf("%f",&FinalTemperature);
  printf("Enter the weight of water: \n");
  scanf("%f",&M);
  float Q= M*(FinalTemperature-InitialTemperature)*4184 ; // Q is in Joules
  printf("Q=%.2f Joules",Q);
  return 0;
}
