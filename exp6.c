#include <stdio.h>
#include <limits.h>

int matrix_chain_order(int p[], int n) {
    int dp[n][n];
    int i, j, k, L, q;

    for (i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int p[] = {1, 2, 3, 4};
    int n = sizeof(p) / sizeof(p[0]);

    printf("The minimum number of multiplications is: %d\n", matrix_chain_order(p, n));

    return 0;
}