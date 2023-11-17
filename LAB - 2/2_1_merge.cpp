#include<bits/stdc++.h>
using namespace std;

void mergeAllIncreasing(int a[], int p, int q, int r){
    int L[100];
    int R[100];
    int i, j, k;
    int n = 0;
    for(i = p; i<= q;i++){
        L[n] = a[i];
        n++;
    }
    L[n] =999999;
    n = 0;
    for(i = q+1; i<=r;i++){
        R[n] = a[i];
        n++;
    }
     R[n] =999999;

     i = 0;
     j = 0;

     for(k = p; k<= r;k++){
        if(L[i]<= R[j]){
        a[k] = L[i];
        i++;
     }
    else{
        a[k] = R[j];
        j++;
    }
}
}

void mergeSortIncreasing(int a[], int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergeSortIncreasing(a,p,q);
        mergeSortIncreasing(a, q+1, r);
        mergeAllIncreasing(a,p,q,r);
    }
}

void mergeAllDecreasing(int a[], int p, int q, int r){
    int L[100];
    int R[100];
    int i, j, k;
    int n = 0;
    for(i = p; i<= q;i++){
        L[n] = a[i];
        n++;
    }
    L[n] = -999999;
    n = 0;
    for(i = q+1; i<=r;i++){
        R[n] = a[i];
        n++;
    }
     R[n] = -999999;

     i = 0;
     j = 0;

     for(k = p; k<= r;k++){
        if(L[i]>= R[j]){  
        a[k] = L[i];
        i++;
     }
    else{
        a[k] = R[j];
        j++;
    }
}
}

void mergeSortDecreasing(int a[], int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergeSortDecreasing(a,p,q);
        mergeSortDecreasing(a, q+1, r);
        mergeAllDecreasing(a,p,q,r);
    }
}

int main(){
    int v[] = {5,2,4,7,1,3,2,6};
    int p = 0;
    int r = 7;

   mergeSortIncreasing(v,p,r);
   cout << "\nMerge sort in increasing order : ";
    for(int i = 0 ; i<= r;i++){
        cout << v[i] << "  ";
    }

   mergeSortDecreasing(v,p,r);
   cout << "\nMerge sort in decreasing order : ";
    for(int i = 0 ; i<= r;i++){
        cout << v[i] << "  ";
    }
    return 0;
}