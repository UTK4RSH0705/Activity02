#include <stdio.h>
int sum(int n);
int main() 
{
    int a;
    printf("Enter the number:");
    scanf("%d",&a);
    
    printf("The Final Result is:%d",sum(a));

    return 0;
}

int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return n*n+sum(n-1);
    }
}
