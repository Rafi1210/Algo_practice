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
// Check number of degree of a vertex
       for (int i = 0; i < n; i++)
    {
    	cout << " List -> " << i << " : ";
    	for(auto j = ad[i].begin() ; j < ad[i].end() ; j++){

			cout << *j << " ";
    	}
    	cout  << "\nDegree of " << i << " : "<< ad[i].size() << " \n";
    }

 // Check if there is an edge between vertices x and y
int x, y;
cin >> x >> y;
bool edgeExists = false;

for (auto neighbor : ad[x]) {
    if (neighbor == y) {
        edgeExists = true;
        break;
    }
}

if (edgeExists) {
    cout << "YES\n";
} else {
    cout << "NO\n";
}

    return 0;
}
