#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>v;
    v.push_back(7);
    v.push_back(8);
    printVec(v);
    vector<int> v2=v;
    v2.push_back(5);
    cout<<"printing vector v: "<<endl;
    printVec(v);
    cout<<"printing copied array v2: "<<endl;
    printVec(v2); // one element is added extra by pushback fxn
}