// #include <stdio.h> //Exercise12 loop
// int main (){
//     int total=0;

//     do{
//         printf ("Enter the number");
//         scanf("%d",&total);
//         total++ ;
//         printf ("Your total is %d/n",total);
//     }
//     while (total <=50);
//     printf("Bye\n");
//     return 0 ;
// }
// #include <stdio.h> //Exercise 13 loop
// int main (){
//     int i=0;
//     do{
//         printf ("Enter the number:");
//         scanf("%d",&i);
//     }
//     while (i<5);
//      {
//         printf("The last number you enter was a %d",i);
//     }
// }
// #include <stdio.h> //Ex14
// #include <ctype.h>
int main () {
    int num1 , num2, sum;
    char r ;
    printf ("Enter the num1:");
    scanf("%d",&num1);
    printf("Enter the num2:");
    scanf("%d",&num2);
    sum = num1 + num2 ;
    printf("do you want to add another number? y/n:");
    scanf("%c",&r);
    printf("The total is %d",sum);
    //if and while  condition 
     char r='y';
     if(r='y'){
         printf("The total is %d",sum);
     }
    while (r='y'){
         printf ("Enter the num1:");
         scanf("%d",&num1);
         printf("Enter the num2:");
         scanf("%d",&num2);
        sum = num1 + num2 ;
        

    }
