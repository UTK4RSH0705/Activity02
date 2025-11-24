#include <stdio.h>

int main()
{
    FILE *fptr;
    
    int menu;
    printf("Menu:\n1.Enter candidate name\n2.Show the list of the candidate\n3.Exit\nOption:");
    scanf("%d",&menu);
    
    switch(menu)
    {
        case 1:
        
        int num;
        printf("Number fo candidates:");
        scanf("%d",&num);
        
        fptr=fopen("candidate.txt","a");
        char name[10];
        printf("Enter candidates name(Give space at end):\n");
        
        for(int i=0;i<num;i++)
        {
          scanf(" %49[^\n]",&name);
          fprintf(fptr,"%s",name);
        }
        fclose(fptr);
        printf("Name saved to file...");
        break;
        
        case 2:
        
        fptr=fopen("candidate.txt","r");
    
        printf("\n\nList of the candidate is:  ");
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
    }

    return 0;
}
