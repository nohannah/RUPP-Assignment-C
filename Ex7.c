#include <stdio.h>
#include <ctype.h>
int main (){
    int user;
 printf("Enter the character:");
 scanf ("%c",&user);
 if (isalpha(user)){
     printf("'%c'is an alphabat.",user);
 }
 else if (isdigit(user)){
     printf("'%c' is a digit.",user);
 }
 else{
     printf("'%c'is a symbol.",user);
 }
 return 0;
}