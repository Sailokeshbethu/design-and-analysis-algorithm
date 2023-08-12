#include <stdio.h>
int main()
{
    int n; 
    printf("Enter the number of rows: "); 
    scanf("%d", &n); 
    for (int i = 1; i <= n; i++) 
    {
        for (int k = 1; k <= n - i; k++) 
        {
            printf("   "); 
        }
        for (int j = 1; j <= i; j++) 
        {
            printf("%d ", j); 
            if (j < i) 
            {
                printf("   "); 
            }
        }
        printf("\n"); 
    }
    return 0;
}
