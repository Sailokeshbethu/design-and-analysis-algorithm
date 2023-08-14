#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int numbers[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (numbers[i] < min1) {
            min2 = min1;
            min1 = numbers[i];
        } else if (numbers[i] < min2 && numbers[i] != min1) {
            min2 = numbers[i];
        }
    }
    if (min1 == INT_MAX || min2 == INT_MAX) {
        printf("Less than two distinct minimum values found.\n");
    } else {
        printf("The first two minimum values are: %d and %d\n", min1, min2);
    }
    
    return 0;
}
