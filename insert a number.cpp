#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int list[MAX_SIZE];
    int size, position, number;
    printf("Enter the size of the list (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid list size. Exiting the program.\n");
        return 1;
    }
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }
    printf("Enter the position to insert the number (0-based index):\n ");
    scanf("%d", &position);
    if (position < 0 || position > size) {
        printf("Invalid position. Exiting the program.\n");
        return 1;
    }
    printf("Enter the number to insert: ");
    scanf("%d", &number);    
    for (int i = size; i > position; i--) {
        list[i] = list[i - 1];
    }
    list[position] = number;
    size++; 
    printf("The list after insertion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
