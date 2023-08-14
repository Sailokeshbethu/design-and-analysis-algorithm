#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int num1, num2;
    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Illegal input\n");
        return 1;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (c != ' ') {
            printf("Illegal input\n");
            return 1;
        }
    }

    if (num2 == 0) {
        printf("Illegal input: Second number cannot be zero.\n");
        return 1;
    }
    int result = gcd(abs(num1), abs(num2));

    printf("GCD of %d and %d is %d\n", num1, num2, result);

    return 0;
}

