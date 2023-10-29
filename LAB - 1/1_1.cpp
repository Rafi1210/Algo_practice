#include<bits/stdc++.h>
using namespace std;

bool bSearch(vector<int> &a, int p , int r, int key){
if(p<=r){
    int mid = (p+r)/2;
    if(key == a[mid]){
        printf("Key Found!");
        return true;
    }
    else if (key < a[mid]){
        return bSearch(a, p, mid-1, key);
    }
    else{
        return bSearch(a, mid+1, r, key);
    }
}
    printf("Key not found!");
    return false;
}


 int main(){
    vector<int> a = {3,5,7,10,13,18,20};
    
    bSearch(a, 0, a.size(), 5);

    return 0;
 }