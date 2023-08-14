#include <stdio.h>
#include <stdlib.h>
void printSubsets(int set[], int n) {
    for (int i = 0; i < (1 << n); i++) {
        printf("{ ");
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                printf("%d ", set[j]);
            }
        }
        printf("}\n");
    }
}

int main() {
    int n;

    printf("Enter the size of the set: ");
    scanf("%d", &n);

    int *set = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Subsets of the given set:\n");
    printSubsets(set, n);

    free(set);
    return 0;
}
