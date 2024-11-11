#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int N;
    cin>>N;
    vector<int>v[N];
    for(int i=0;i<N;++i){
        int n;
        cin>>n;
        for(int j=0;j<n;++j){
           int x;
           cin>>x;
           v[i].push_back(x);  // v[i] is the ith vector or only one vector
        }
    }
    for(int i=0;i<N;++i){
        printVec(v[i]);
        /* v[0][0]=> 0 th vector ka 0th element
         array of vector mein number of rows fixed hai par number of coloumn dynamic hai */
    }
}