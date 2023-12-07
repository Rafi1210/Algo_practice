#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e, u,v;
    int ad[10][10];
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v ;
        ad[u][v] = 1;
        ad[v][u] = 1;
        cout <<"taken" << endl;
    }
      for (int i = 0; i < e; i++){
		 cout  << "\t"<< i;
      }
      cout << endl;
      for (int i = 0; i < e; i++)
    {
    	cout << i << "\t" ;
       cout << ad[u][v] << "\t";
       cout << ad[v][u] << endl;
    }

    return 0;
}
