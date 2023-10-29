#include <bits/stdc++.h>
using namespace std;


int main(){ 

    double arr[] = {9.00,9.40};
    double dep[] = {9.10, 12.00};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    int platform = 0;

    sort(begin(arr),end(arr));
    sort(begin(dep),end(dep));

    for(int i = 0; i < n ; ++i){
        printf("%.2lf ", arr[i]);
    }

    cout << "\n";
     for(int i = 0; i < n ; ++i){
        printf("%.2lf ", dep[i]);
    }

    for(int i = 0 ; i < n - 1; ++i){
       if((arr[i] - arr[i+1]) >= (dep[i]- dep[i+1])){
        platform++;
       }
    }
    cout << "\nMinimum platforms required: "  << platform;
   
    return 0;
}