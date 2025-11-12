#include <stdio.h>
#include <string.h>

struct student 
{
    char name[100];
    char year[10];
    char branch[15];
    int roll;
};

int main() 
{
    struct student s[100];

    strcpy(s[0].name, "Utkarsh");
    strcpy(s[0].year, "First");
    strcpy(s[0].branch, "Computer");
    s[0].roll = 10000;

    strcpy(s[1].name, "Nishant");
    strcpy(s[1].year, "Second");
    strcpy(s[1].branch, "E&TC");
    s[1].roll = 10001;

    strcpy(s[2].name, "Kushal");
    strcpy(s[2].year, "Third");
    strcpy(s[2].branch, "IT");
    s[2].roll = 10002;

    strcpy(s[3].name, "Shashank");
    strcpy(s[3].year, "First");
    strcpy(s[3].branch, "Mechanical");
    s[3].roll = 10003;

    strcpy(s[4].name, "Uday");
    strcpy(s[4].year, "Fourth");
    strcpy(s[4].branch, "AIDS");
    s[4].roll = 10004;

    int menu;
    int total = 5;  

start:
    printf("Menu:\n1. Search in Directory\n2. Add new information\n3. Exit\nOption: ");
    scanf("%d", &menu);
    printf("\n");

    switch (menu) 
    {
        case 1: 
        {
            int search_roll;
roll_input:
            printf("Enter the roll no. (5 digits): ");
            scanf("%d", &search_roll);
            printf("\n");

            if (search_roll >= 10000 && search_roll <= 99999) 
            {
                int found = 0;
                for (int i = 0; i < total; i++) 
                {
                    if (search_roll == s[i].roll) 
                    {
                        printf("The information of given roll no. is:\n");
                        printf("Name: %s\n", s[i].name);
                        printf("Academic Year: %s\n", s[i].year);
                        printf("Branch: %s\n", s[i].branch);
                        printf("Roll No.: %d\n\n", s[i].roll);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    printf("No record found for Roll No. %d\n\n", search_roll);
            } 
            else 
            {
                printf("|| Enter Valid Roll Number ||\n");
                goto roll_input;
            }
            goto start;
        }

        case 2: 
        {
            int m;
            printf("Enter the number of students to add: ");
            scanf("%d", &m);

            for (int q=total;q<total+m;q++) 
            {
                printf("Enter Student Name: ");
                scanf("%s", s[q].name);
                printf("Enter Academic Year (In Words): ");
                scanf("%s", s[q].year);
                printf("Enter Student Branch: ");
                scanf("%s", s[q].branch);
                printf("Enter Student Roll No. (5 Digits): ");
                scanf("%d", &s[q].roll);
            }

            total=total+m;

            printf("\nData added successfully!\n\n");
            goto start;
        }

        case 3:
            printf("Exiting program...\n");
            break;

        default:
            printf("Choose the correct option!\n\n");
            goto start;
    }

    return 0;
}
