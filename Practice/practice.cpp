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
