#include <stdio.h>

int sum(int a, int d, int n);

int main() 
{
    int a, d, n;

    printf("Enter the first term: ");
    scanf("%d", &a);
    printf("Enter the difference: ");
    scanf("%d", &d);
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int result = sum(a, d, n);
    printf("Sum = %d\n", result);

    return 0;
}

int sum(int a, int d, int n)
{
    if (n == 0)
        return 0;
    else {
        int term = a + (n - 1) * d;
        return term + sum(a, d, n - 1);
    }
}
