#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e, u,v;
    vector<int> ad[100];
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v ;
        ad[u].push_back(v);
        ad[v].push_back(u);
        cout <<"taken" << endl;
    }
      for (int i = 0; i < n; i++)
    {
    	cout << "vector -" <<  i ;
    	for(int j = 0 ; j < ad[i].size() ; j++){
			cout << " -> " << ad[i][j] ;
    	}
    	cout << "\n";
    }

    return 0;
}
