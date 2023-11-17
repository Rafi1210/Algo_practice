#include <iostream>
using namespace std;

int dp[1001][1001];
int tb[1001][1001];

int knapsack(int weight[], int value[], int cap, int numofitems) {
    for(int i = 0; i <= numofitems; i++) {  // Initializing the first col of the dp array 

        dp[i][0] = 0;
    }

    for(int i = 0; i <= cap; i++) {   // Initializing the first row of the dp array

        dp[0][i] = 0;
    }

    for(int i = 1; i <= numofitems; i++) { 
        for(int j = 1; j <= cap; j++) {

            //main part of the code 
            // l1 and l2 is type of counter where store the value of each indices
            int l1= value[i] + dp[i - 1][j - weight[i]];
            int l2= dp[i - 1][j];
            // j is capacity...
            if(weight[i] <= j) {
                if(l1>= l2) {
                    dp[i][j] = l1;
                    tb[i][j] = 1;
                }
                else {
                    dp[i][j] = l2;
                    tb[i][j] = 0;
                }
            }
            else {  // weight[i] > j  it is not possible as if w[i] = 3 , i = 3, j = 2 , for l1 = dp[2][-1] , which is not possible , so else conition
                dp[i][j] = dp[i - 1][j]; 
                tb[i][j] = 0;
            }
        }
    }
    return dp[numofitems][cap];
}

void traceback(int n, int w[], int v[], int cap) {
    if(n == 0 || cap == 0) return;

    if(tb[n][cap] == 1) {
        cout << "Item : " << n << endl;
        traceback(n - 1, w, v, cap - w[n]);
    }
    else {
        traceback(n - 1, w, v, cap);
    }
}

int main() {
    int cap;
    cin >> cap;

    int numofitems;
    // cout << "Enter the number of total items: ";
    cin >> numofitems;

    int weight[1001];
    int value[1001];

    for(int i = 1; i <= numofitems; i++) {
        cin >> weight[i];
        cin >> value[i];
    }

    cout << "Total Profit: " << knapsack(weight, value, cap, numofitems);
    cout << endl;
    traceback(numofitems, weight, value, cap);
    return 0;
}
