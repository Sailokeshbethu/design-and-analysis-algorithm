#include <stdio.h>


unsigned long long binomialCoefficient(int n, int k) {
    unsigned long long dp[n + 1][k + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k && j <= i; j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;
    printf("Enter the values of n and k: ");
    scanf("%d %d", &n, &k);

    if (n < 0 || k < 0 || k > n) {
        printf("Invalid input.\n");
        return 1;
    }

    unsigned long long result = binomialCoefficient(n, k);
    printf("C(%d, %d) = %llu\n", n, k, result);

    return 0;
}

