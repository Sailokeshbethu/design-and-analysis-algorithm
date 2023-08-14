#include <stdio.h>

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size, m, n;

   
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

   
    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter M and N: ");
    scanf("%d %d", &m, &n);

    if (m <= 0 || n <= 0 || m > size || n > size) {
        printf("Illegal input\n");
        return 1;
    }
    sortArray(arr, size);

    int mthMax = arr[size - m];
    int nthMin = arr[n - 1];

    int sum = mthMax + nthMin;
    int diff = mthMax - nthMin;

    printf("M-th maximum: %d\n", mthMax);
    printf("N-th minimum: %d\n", nthMin);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);

    return 0;
}

