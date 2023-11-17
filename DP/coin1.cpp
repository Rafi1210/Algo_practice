/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*/

#include <bits/stdc++.h>
using namespace std;

int minCoins(int amount, int coins[], int n) {
    int dp[amount + 1];
    dp[0] = 0; // Base case: 0 coins needed to make up amount 0

    for (int i = 1; i <= amount; ++i) {
        dp[i] = INT_MAX; // Initialize with a large value, representing no valid solution yet
        for (int j = 0; j < n; ++j) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
    int amount = 11;
    int coins[] = {1,2,5};
    int n = sizeof(coins) / sizeof(coins[0]);
    int ans = minCoins(amount, coins, n);

    if (ans == -1) {
        cout << "It's not possible to make up the given amount with the provided coins." << endl;
    } else {
        cout << "The fewest number of coins needed is: " << ans << endl;
    }

    return 0;
}
