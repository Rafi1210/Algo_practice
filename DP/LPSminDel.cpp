#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int trace[101][101];

void traceback(char x[], char y[], int n , int m){
	if(n == 0 || m == 0)	return;

	if(trace[n][m] == 1){
		traceback(x,y,n-1,m-1);
		cout << x[n-1];
	}
	else if(trace[n][m] == 2){
		traceback(x,y,n,m-1);
	}
	else if(trace[n][m] == 3){
		traceback(x,y,n-1,m);
	}
}

int lcs(char x[], char y[], int n, int m) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (x[i - 1] == y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                trace[i][j] = 1;
            } else {
                int l1 = dp[i][j-1];
                int l2 = dp[i-1][j];
                if (l1 >= l2) {
                    dp[i][j] = l1;
                    trace[i][j] = 2;
                } else {
                    dp[i][j] = l2;
                    trace[i][j] = 3;
                }
            }
        }
    }
    return dp[n][m];
}

int main() {
    char x[100];
    int n, m;
    cout << "X: ";
    cin >> x;
    n = strlen(x);
	char y[n];
    m = n;
    for(int i = 0, j = n-1;j>=0;i++,j--){
		y[i] = x[j];
    }
     cout << "\nY: ";
    for(int i = 0 ; i  < n ;i++){
		cout << y[i] << " ";
    }

    memset(dp, 0, sizeof(dp));
    int len = lcs(x, y, n, m);
    int minChar = n - len;

    cout << "Length of LONGEST PALINDROMIC SUB-SEQUENCE : " << len << endl;
    cout << "LPS: ";
    traceback(x, y, n, m);
    cout << "\nMinimum character need to delete to make X Palindrome : " << minChar;

    return 0;
}
