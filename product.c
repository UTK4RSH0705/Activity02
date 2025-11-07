#include <stdio.h>

struct product
{
    char name[10];
    int IDno;
    int price;
};

int main()
{
    int m, n;
    printf("Enter number of products: ");
    scanf("%d", &n);
    printf("\n");

    struct product P[15];
    
    // Input product details
    for (m = 0; m < n; m++)
    {
        printf("Enter Product Name: ");
        scanf("%s", P[m].name);

        printf("Enter Product ID Number: ");
        scanf("%d", &P[m].IDno);

        printf("Enter Product Price: ₹");
        scanf("%d", &P[m].price);
        printf("\n");
    }
    
    // Sorting products in descending order of price
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (P[j].price < P[j + 1].price)
            {
                struct product temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }

    // Display sorted list
    printf("\nThe list of the products in descending order of price is:\n");
    printf("--------------------------------------------------------\n");
    for (m = 0; m < n; m++)
    {
        printf("Name: %s | ID no.: %d | Price: ₹%d\n", P[m].name, P[m].IDno, P[m].price);
    }

    return 0;
}
