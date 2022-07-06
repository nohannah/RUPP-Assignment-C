#include <stdio.h>
int main (){
    int num;
    printf("Enter the number:");
    scanf("%d",&num);
    
    if(num>20){
        printf("To high:%d",num);
    }
    else{
        printf("Thankyou");
    }
    return 0;
}