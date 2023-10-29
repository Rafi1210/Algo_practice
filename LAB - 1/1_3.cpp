#include<bits/stdc++.h>
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

 int main(){
    vector<int> a = {1,1,0,0,0};
    int key = 0;
    int x = Searchfirst(a, 0, a.size(), 0);

    int count = 0;

    if(a[x+(a.size()/2)-1] >= key){
        count++;
    }
printf("\n Number of %d occurs %d times\n",key, count);
    return 0;
 }