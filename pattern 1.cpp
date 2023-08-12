#include <stdio.h>

long long binomialCoeff(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

void generatePascalTriangle(int numRows) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%lld ", binomialCoeff(i, j));
        }
        printf("\n");
    }
}

int main() {
    int numRows = 5;

    printf("Pascal's Triangle (up to %d rows):\n", numRows);
    generatePascalTriangle(numRows);

    return 0;
}

