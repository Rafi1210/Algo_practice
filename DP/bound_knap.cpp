/*Unbounded knapsack means infinite numbers of element
I can take the elements infinite times. The cap will be same always, it will never decrease.*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(int W[], int val[], int n, int cap) {
     int dp[n+1][cap+1];
     memset(dp, -1, sizeof(dp));// set -1 to all the index of the dp array until end
   if(n == 0 || cap == 0){  //cap = 0 means no capacity to store the product and n = 0 means there is no product
    return dp[n][cap] = 0;
   }
   if(dp[n][cap] != -1){ // dp array is set to -1, if it not -1 then return the saved dp array's index value
   return dp[n][cap];
   }
   else{
    if(cap >= W[n]){ // it means still there is space to store product into the sack & here n - 1 means product is taken in first call and product will be not taken in 2nd call
    return dp[n][cap] = max((val[n]+knapsack(W, val, n - 1, cap-W[n])), knapsack(W, val, n - 1, cap));
    }
    else{ // There is no capacity left to store , for that -1
        return dp[n][cap] = knapsack(W, val, n - 1, cap);
    }
   }
}

int main() {
    int cap = 10;
    int val[] = {10, 13, 5, 100};
    int wt[] = {5, 1, 7, 3};
    int n = sizeof(val) / sizeof(val[0]);

    cout << "Maximum value that can be obtained: " << knapsack(wt, val, n, cap) << endl;

    return 0;
}
