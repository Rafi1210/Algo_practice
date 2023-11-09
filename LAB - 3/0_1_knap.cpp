#include <bits/stdc++.h>
using namespace std;

int knapsack(int W[], int val[], int n, int cap, int dp[101][1001]) {
    if (n == 0 || cap == 0) {
        return 0;
    }

    if (dp[n][cap] != -1) {
        return dp[n][cap];
    }

    if (W[n - 1] <= cap) {
        int include = val[n - 1] + knapsack(W, val, n - 1, cap - W[n - 1], dp);
        int exclude = knapsack(W, val, n - 1, cap, dp);
        dp[n][cap] = (include > exclude) ? include : exclude;
    } else {
        dp[n][cap] = knapsack(W, val, n - 1, cap, dp);
    }

    return dp[n][cap];
}

int main() {
    int cap = 10;
    int val[] = {10, 13, 5, 100};
    int wt[] = {5, 1, 7, 3};
    int n = sizeof(val) / sizeof(val[0]);

    int dp[101][1001];
    memset(dp, -1, sizeof(dp));

    int result = knapsack(wt, val, n, cap, dp);

    cout << "Maximum value that can be obtained: " << result << endl;

    return 0;
}
