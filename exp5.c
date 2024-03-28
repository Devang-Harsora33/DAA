#include <stdio.h>
#include <limits.h>

int min_coins(int coins[], int n, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            if (dp[j - coins[i]] != INT_MAX) {
                dp[j] = (dp[j] < dp[j - coins[i]] + 1) ? dp[j] : dp[j - coins[i]] + 1;
            }
        }
    }

    return dp[amount];
}

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100};
    int n = sizeof(coins) / sizeof(coins[0]);

    printf("Enter the purchase amount: ");
    int amount;
    scanf("%d", &amount);

    printf("Enter the amount paid by the customer: ");
    int paid;
    scanf("%d", &paid);

    int min_coins_needed = min_coins(coins, n, amount);

    if (min_coins_needed == INT_MAX) {
        printf("No combination of coins can make up the change.\n");
    } else {
        printf("The minimum number of coins needed for change is: %d\n", min_coins_needed);

        int remaining = amount;
        printf("The combination of coins that make up the minimum number is: ");
        for (int i = n - 1; i >= 0; i--) {
            while (remaining >= coins[i]) {
                printf("%d ", coins[i]);
                remaining -= coins[i];
            }
        }
        printf("\n");
    }

    return 0;
}