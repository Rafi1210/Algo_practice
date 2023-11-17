/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int ways(int amount, int coins[], int n) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= amount; ++j) {
            if (j == 0) {
                dp[i][j] = 1;
            } else if (i == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j];
                if (coins[i - 1] <= j) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }
    }
    return dp[n][amount];
}

int main() {
    int amount = 5;
    int coins[] = {1,2,5};
    int n = sizeof(coins) / sizeof(coins[0]);
    int ans = ways(amount, coins, n);
    cout << ans << endl;
    return 0;
}
