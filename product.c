#include <stdio.h>

struct product
{
    char name[10];
    int IDno;
    int price;
    int quantity;
};

int main()
{
    int n;
    printf("Enter number of products: ");
    scanf("%d", &n);
    printf("\n");

    struct product P[15];
    
    for (int m = 0; m < n; m++)
    {
        printf("Enter Product Name: ");
        scanf("%s", P[m].name);

        printf("Enter Product ID Number: ");
        scanf("%d", &P[m].IDno);

        printf("Enter Product Price: ₹");
        scanf("%d", &P[m].price);

        printf("Enter Product Quantity: ");
        scanf("%d", &P[m].quantity);

        printf("\n");
    }

    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (P[j].price < P[j + 1].price ||
               (P[j].price == P[j + 1].price && P[j].quantity < P[j + 1].quantity))
            {
                struct product temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }

    printf("\nThe list of the products in descending order of price\n");
    printf("(If prices are same, sorted by quantity):\n");
    printf("---------------------------------------------------------\n");

    for (int m = 0; m < n; m++)
    {
        printf("Name: %s | ID no.: %d | Price: ₹%d | Quantity: %d\n",
               P[m].name, P[m].IDno, P[m].price, P[m].quantity);
    }

    return 0;
}
