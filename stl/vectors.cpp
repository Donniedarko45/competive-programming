#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> v){
    for(int i=0;i<v.size();++i){
        cout<<v[i];
    }
    cout<<endl;
}

int main(){
    vector<int> v; 
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        v.push_back(x); // jo bhi value pushback ko provide kr rhe ho wo vector ke end me dal jayegi
    }
    printVec(v);
}