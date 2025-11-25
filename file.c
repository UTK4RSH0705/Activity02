#include <stdio.h>

int main()
{
    FILE *fptr;
    
    int menu;
    printf("Menu:\n1.Enter candidate Information\n2.Show the list of the candidate\n3.Exit\n4.Delete the file\nOption:");
    scanf("%d",&menu);
    printf("\n");

    
    switch(menu)
    {
        case 1:
        
        int num;
        printf("Number fo candidates:");
        scanf("%d",&num);
        printf("\n");

        
        fptr=fopen("candidate.txt","a");
        char name[10];
        int age,serialno;

        for(int i=0;i<num;i++)
        {
          printf("Enter candidates name(Give space at end):");
          scanf(" %49[^\n]",&name);
          printf("Enter age:");
          scanf("%d",&age);
          printf("Enter serial no.:");
          scanf("%d",&serialno);
          printf("\n");

          fprintf(fptr,"Name:%s\nAge:%d\nserial no.:%d\n\n",name,age,serialno);  
        }
        fclose(fptr);
        printf("Information saved to file...");
        break;
        
        case 2:
        
        fptr=fopen("candidate.txt","r");
    
        printf("\n\nList of the candidate is: \n\n");
        char ch;
        while((ch=fgetc(fptr))!=EOF)
        {
            putchar(ch);
        }
        fclose(fptr);
        break;

        case 3:
        
        printf("Exititng the program....");
        break;
        
        case 4:
        
        fptr=fopen("candidate.txt","w");
        fclose(fptr);
        printf("Deleting the file...");
        
    }

    return 0;
}
