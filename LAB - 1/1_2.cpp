#include <bits/stdc++.h>
using namespace std;

int Searchfirst(vector<int> &a, int p, int r , int key){
    if(p <= r){
        int mid = (p+r)/2;
        if((key == a[mid]) && ((mid == 0) || a[mid-1] < key)){
            printf("Found the first occurance!");
            return mid;
        }
        else if(key < a[mid]){
            return Searchfirst(a, p, mid-1, key);
        }
        else {
            return  Searchfirst(a, mid+1, r, key);
    }
    }
    printf("!Found");
    return -1;
}


int main() {

    vector<int> a = {3,5,7,7,10,13,18,20};
    int key = 7;
    int count;
// condition for searching the number and count all the occurance
   int x = Searchfirst(a,0, a.size(), key);

    printf("\n%d\n", x);

    if(a[x+(a.size()/2)-1] == key){
        count++;
    }
    
    if(count ==  (a.size()/2)){
        printf("%d is present in the list at least n/2 times .\n", key);
    }
    else{
        printf("%d is not present in the list at least n/2 times .\n", key)
    }

    return 0;
}
