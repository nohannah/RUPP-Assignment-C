#include<stdio.h> 
int x,y,z;
int main() 
{
    printf("Enter x: ");
    scanf("%d",&x);
    printf("\nEnter y:");
    scanf("%d",&y);
    if (x>2)
    {
        if(y>2)
        {
            z = x + y;
            printf("z is %d",z);
        }
        else{
            printf("x is %d",x);
        }
    }
}