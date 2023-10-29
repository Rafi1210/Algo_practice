#include <bits/stdc++.h>
using namespace std;

struct job{
    int deadline,profit;
    char id;
};

bool compareByProfit(const job& a, const job& b) {
    return a.profit > b.profit;
}

int main(){    
    int n;
    cin >> n;
    struct job List[n];
    for(int i = 0;i<n ;++i){
        cin >> List[i].id >> List[i].deadline >> List[i].profit;
    }
    //List: The first argument :  it's the beginning of the List array.
    //List + n: The second argument :  it points to the element just after the last element in the array.
    sort(List, List + n, compareByProfit);

    char schedule[n];
    for(int i = 0 ; i < n ; ++i){
        schedule[i] = -1;
    }

    for(int i = 0 ; i < n ; ++i){
        int d = List[i].deadline;
        for(int j = d ; j > 0 ; --j){
            if(schedule[j] == -1){
                schedule[j] = List[i].id;
                break;
            }
        }
    }

    for(int i = 0;i<n ;++i){
        cout << List[i].id << " ";
    }
    
    cout << "The maximum profit sequence of job :" ;
    for(int i = 0 ; i < n ; ++i){
        cout  << schedule[i] << " ";
    }
    return 0;
}