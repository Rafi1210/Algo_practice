#include <bits/stdc++.h>
using namespace std;

int fibo(int n, int dp[]) {
    if (n == 0) {
        return dp[n] = 0;
    }
    if (n == 1) {
        return dp[n] = 1;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    else{
    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}
}
int main() {
    int dp[100];
    memset(dp, -1, sizeof(dp));
    int n = 10;
    int ans;
    for(int i = 0 ; i <= n ; ++i){
    ans = fibo(i, dp);
    cout << ans << endl;  
    }
    
    return 0;
}
