#include <stdio.h>

int Length(char s[]);
int Compare(char a[], char b[]);
void Concatenating(char dest[], char src[]);

int main()
{
    char firstname[50], lastname[50],fullName[100];
    int choice;

    printf("Enter student's first name: ");
    scanf("%s",&firstname);

    printf("Enter student's last name: ");
    scanf("%s",&lastname);

    
    printf("\n===== STUDENT NAME MANAGE=====\n");
    printf("1. Find length of first and last name\n");
    printf("2. Compare first name and last name\n");
    printf("3. Create full name \n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();

    switch(choice) 
{
    case 1:
        
    printf("Length of first name = %d\n", Length(firstname));
    printf("Length of last name  = %d\n", Length(lastname));
    break;

    case 2:
    
    if(Compare(firstname, lastname) == 0)
    {
        printf("Both names are EQUAL\n");
    }
    else
    {
         printf("Names are DIFFERENT\n");
    }
    break;

    case 3:
    
    Concatenating(fullName, firstname);
    Concatenating(fullName, " ");
    Concatenating(fullName, lastname);
    printf("Full Name: %s\n", fullName);
    break;

    case 4:
    
    printf("Exiting...\n");
    break;

    default:
    
    printf("Invalid option!\n");
              
}
    return 0;
}

int Length(char s[]) 
{
    int i = 0;
    while(s[i] != '\0')
    {
        i++;
    }
    return i;  
}

int Compare(char a[], char b[]) {
    int i = 0,j=0;
    while(a[i] != '\0') 
    {
        i++;
    }
    while(b[j] != '\0') 
    {
        j++;
    }
    if(i==j)
    {
        return 0;
    }
    return 1;
}

void Concatenating(char dest[], char src[]) 
{
    int i = 0, j = 0;

    while(dest[i] != '\0') 
    {
        i++;
    }    

    while(src[j] != '\0')
    {
        dest[i++] = src[j++];
    }    

    dest[i] = '\0';
}
