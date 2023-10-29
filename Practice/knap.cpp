#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
vector<PII> v;

bool cmp(PII A, PII B){
    return A.second*B.first > A.first * B.second;
}

void fractionalKnapsack(){
    int n, W;
    cout << "Enter Maximum Weight : ";
    cin >> W;
    cout << "\nEnter number of product : ";
    cin >> n;
    for(int i = 0;i<n;++i){
        int weight , price;
        printf("\nEnter Weight of element %d : ", i);
        cin >>  weight;
        printf("\nEnter Price of element %d : ", i);
        cin >> price;
        cout << "\n";
        v.push_back(PII(weight, price));
    }
    sort(v.begin(), v.end(), cmp);
    
    int ans  = 0;
    for(int i = 0;i< n;++i){
        int z = min(W,v[i].first);
        W-=z;
        ans += z*v[i].second;
    }
    cout << "Maximum Cost : " << ans << "\n";
}

int main(){

    fractionalKnapsack();
    return 0;
}