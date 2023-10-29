#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
/*
#In the array i & j are in the same position. First, i remains as it is j traverse the array, 
#if(a[j]<=pivot)-----> increase (i + 1) and swap(a[i],a[j])---->(values) , 
#i and j remain in the same position just change or swap the values
#Fianlly , if(a[j]==pivot) ------> swap(&a[i+1], &a[r]) , here i is last swapped index, return i+1 the index of pivot
#So quick sort ensures the position of it's pivot and calls recursively to sort the each partitioned part
*/
int partition(vector<int> &a, int p, int r) {
    int pivot = a[r]; // Choose the rightmost element as the pivot
    int i = p-1; // Initialize the index of the smaller element

    for (int j = p; j < r; ++j) {
        // If the current element is smaller than or equal to the pivot
        if (a[j] <= pivot) { 
            ++i; // Move the index of the smaller element
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i+1], &a[r]); // Put the pivot in its correct place
    return (i+1); // Return the index of the pivot element
}


void quickSort(vector<int> &a, int p, int r){
    if (p < r) {
        // Partition the array into two sub-arrays
        int partitionIndex = partition(a, p, r);

        // Recursively sort the sub-arrays
        quickSort(a, p, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, r);
    }
}

int main() {
    vector<int> A = {3, 7, 2, 15, 8, 12, 61, 6};

    quickSort(A, 0,A.size()-1);

    cout << "Sorted array: ";
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
