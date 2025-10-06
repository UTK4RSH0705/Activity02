#include <stdio.h>

int main() {
    int temp,coolingsystem=0;
    printf("Enter the Current Room Temperature");
    scanf("%d",&temp);
    if(temp<0)
    {
        printf("Invalid Temperature");
    }
    else
    {
        if(temp>30)
        {
            coolingsystem=1;
            printf("The Temperature is above the limit\n");
            printf("The cooling has been turned on");
        }
        else
        {
            coolingsystem=0;
            printf("The Temperature is below or equal to the limit\n");
            printf("The cooling has been turned off");
        }
    }
    return 0;
}
