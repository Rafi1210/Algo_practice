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

int lcs(char x[], char y[], int n , int m){
	if(n == 0 || m == 0){
		return 0;
	}
	if(dp[n][m] != -1){
		return dp[n][m];
	}
	if(x[n-1] == y[m-1]){
		trace[n][m] = 1;
		return dp[n][m] = 1 + lcs(x,y,n-1,m-1);
	}
	else if(x[n-1] != y[m-1]){
		int l1 = lcs(x,y,n,m-1);
		int l2 = lcs(x,y,n-1,m);
		if(l1>=l2){
			trace[n][m] = 2;
			return dp[n][m] = l1;
		}
		else{
			trace[n][m] = 3;
			return dp[n][m] = l2;
		}
	}
}

int main() {
    char x[100], y[100];
    int n,m ;
    cout << "X : " ;
    cin >> x;
    cout << "\nY : ";
    cin >> y;
    n = strlen(x);
    m = strlen(y);

 memset(dp, -1, sizeof(dp));
 int len = lcs(x,y,n,m);
 cout << "Length of Recursive LCS : " << len << endl;
 cout  << "LCS : ";
 traceback(x,y,n,m);
    return 0;
}
