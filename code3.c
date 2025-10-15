#include <stdio.h>

int main() {
    //decleration
    char name;
    int company;
    long score;

printf("Enter Your Name:");
scanf("%s",&name);
printf("\n");
start: printf("Enter Your Credit Card Provider:\n");
printf("1.Mastercard\n2.Visa\n3.American Express\n4.Discover\nEnter:");
scanf("%d",&company);
printf("\n");

if(company==1||company==2||company==3||company==4)
{
   printf("Enter Your Credit Score:");
   scanf("%ld",&score);
   printf("\n");
   
   if(score<=850&&score>=350)
   {
     if(score==850)
     {
        printf("You have Excellent Credit Score");
     }
     else if(score>800)
     {
       printf("You have Good Credit Score");
     }
     else if(score>700)
     {
       printf("You have Mediocre Credit Score");
     }
     else if(score>500)
     {
       printf("You have Average Credit Score");
     }
     else if(score>300)
     {
       printf("You have Bad Credit Score");
     }
     else
     {
       printf("You have Worst Credit Score");
     }
   }
    else
   {
       printf("Enter Valid Score");
   }
}
else
{
    printf("\n");
    printf("Enter Valid Provider\n\n");
    goto start;
}
    return 0;
}
