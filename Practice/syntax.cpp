#include <bits/stdc++.h> 
using namespace std;
 
 int main(){
    // vector<int> g1;
 
    // for (int i = 1; i <= 5; i++)
    //     g1.push_back(i);
 
    // cout << "Output of begin and end: ";
    // for (auto i = g1.begin(); i != g1.end(); ++i)
    //     cout << *i << " ";
 
    // cout << "\nOutput of cbegin and cend: ";
    // for (auto i = g1.cbegin(); i != g1.cend(); ++i)
    //     cout << *i << " ";
 
    // cout << "\nOutput of rbegin and rend: ";
    // for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
    //     cout << *ir << " ";
 
    // cout << "\nOutput of crbegin and crend : ";
    // for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
    //     cout << *ir << " ";


 vector<int> v = {1,3,5,3,12,56,76,12};
    // vector<int> v;
    // int n,a;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin>> a;
    //     v.push_back(a);
    // }
    
    cout << "Counting elements : " << v.size() << "\n"; //counts all the element
    cout<< "Maximum element : "<<   *max_element(v.begin(), v.end()) << "\n";//finds max element
    cout<< "Minimum element : "<< *min_element(v.begin(), v.end()) << "\n";//finds min element
    v.erase(v.begin()+2); // counts from 0
   
    for(auto x : v){
         cout<< x << "\n";
    }

    // cout << "Insert Vector : ";
  v.insert(v.begin()+5, 200);

 for(auto x : v){
         cout<< x << "\n";
    }
    
    return 0;
 }


  //---------------------------- VECTOR PAIR------------------------------

//  #include <bits/stdc++.h> 
// using namespace std;
//  void printvec(vector<pair<int, int> >&v){
//    cout << "size : "<< v.size() << endl;
//    for(int i = 0;i<v.size() ;++i){
//       cout << v[i].first << " " << v[i].second << "\n";
//    }
//    cout << endl;
//  }
//   int main(){
//  //  vector<pair<int, int> > v = {{1,2}, {2,3}, {4,5}} ;
//    vector<pair<int, int> > v;
//    printvec(v);
//    int n;
//    cin >> n;
//   for(int i = 0;i<n ;++i){
//       int x, y;
//       cin >>x>>y;
//       v.push_back({x,y});
//    }
//    printvec(v);
//    return 0;
//  }


// //-------------------------------VECTOR OF ARRAYS-----------------------------
// #include <bits/stdc++.h> 
// using namespace std;
//  void printvec(vector<int>&v){
//    cout << "size : "<< v.size() << endl;
//    for(int i = 0;i<v.size() ;++i){
//       cout << v[i] << " ";
//    }
//    cout << endl;
//  }
 
//   int main(){
//    int N;
//    cin >> N;
//    vector<int> v[N];

//   for(int i = 0;i<N ;++i){
//       int n;
//       cin >>n;
//       for(int j = 0; j< n ; ++j){
//          int x;
//          cin >>x;
//          v[i].push_back(x); // ith element push in the vector
//       }
//    }
//    for(int i = 0 ; i < N ; ++i){
//       printvec(v[i]);
//    }
   
//    return 0;
//  }


// //------------------------VECTOR OF VECTORS (DYNAMIC ROW AND COL)---------------------
// #include <bits/stdc++.h> 
// using namespace std;
//  void printvec(vector<int>&v){
//    cout << "size : "<< v.size() << endl;
//    for(int i = 0;i<v.size() ;++i){
//       cout << v[i] << " ";
//    }
//    cout << endl;
//  }
 
//   int main(){
//    int N;
//    cin >> N;
//    vector<vector<int> > v;

//   for(int i = 0;i<N ;++i){
//       int n;
//       cin >>n;
//       vector<int> temp;
//       for(int j = 0; j< n ; ++j){
//          int x;
//          cin >>x;
//          temp.push_back(x); // [i][j]th element push in the vector
//       }
//       v.push_back(temp);
//    }
//    v[0].push_back(10);
//    for(int i = 0 ; i < v.size(); ++i){
//       printvec(v[i]);
//    }
   
//    return 0;
//  }