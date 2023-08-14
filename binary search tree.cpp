  #include <stdio.h>
#include <limits.h>

#define MAX_KEYS 10

int sum(int freq[], int i, int j) {
	int k;
    int s = 0;
    for (k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

int optimalBST(int keys[], int freq[], int n) {
	int i,L,r;
    int cost[n][n];

    for (i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    for ( L = 2; L <= n; L++) {
        for (i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            for (r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int keys[MAX_KEYS] = {10, 12, 20, 40};
    int freq[MAX_KEYS] = {34, 8, 50, 23};
    int n = sizeof(keys) / sizeof(keys[0]);

    int minCost = optimalBST(keys, freq, n);

    printf("Minimum cost of optimal binary search tree: %d\n", minCost);

    return 0;
}  
