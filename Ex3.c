#include <stdio.h>
int main (){
    int age;
    printf("Enter age:");
    scanf("%d",&age);
    int to = 20, ty = 10;
    if (age>=16){
        printf("ticketprice =%d$",to);
    }
    
    else{

        printf("tickketprice=%d$",ty);  
    }
   
    return 0;
}
