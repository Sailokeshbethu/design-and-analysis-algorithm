#include <stdio.h>
#include <stdlib.h>
struct Object {
    int value;
    int weight;
};
int compare(const void *a, const void *b) {
    struct Object *objA = (struct Object *)a;
    struct Object *objB = (struct Object *)b;
    double ratioA = (double)objA->value / objA->weight;
    double ratioB = (double)objB->value / objB->weight;
    return (ratioB > ratioA) ? 1 : -1;
}
double knapsackGreedy(struct Object objects[], int n, int capacity) {
    qsort(objects, n, sizeof(struct Object), compare);

    int currentWeight = 0;
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + objects[i].weight <= capacity) {
            currentWeight += objects[i].weight;
            totalValue += objects[i].value;
        } else {
            double remainingCapacity = capacity - currentWeight;
            totalValue += (remainingCapacity / objects[i].weight) * objects[i].value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    struct Object objects[n];

    printf("Enter the values and weights of the objects:\n");
    for (int i = 0; i < n; i++) {
        printf("Object %d: ", i + 1);
        scanf("%d %d", &objects[i].value, &objects[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxValue = knapsackGreedy(objects, n, capacity);

    printf("Maximum value that can be obtained: %.2lf\n", maxValue);

    return 0;
}

