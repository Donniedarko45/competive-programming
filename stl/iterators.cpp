#include<bits/stdc++.h>
using namespace std;
// vector is also stored in contigous memory
int main(){
    vector<int>v={2,3,4,5,6};
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    /*vector<int>::iterator it=v.begin(); // to declare iterator syntax
    for(it=v.begin();it!=v.end();++it){
        cout<<(*it)<<endl;
    }*/

    vector<pair<int,int>>v_p={{1,2},{3,4},{5,6}};
    vector<pair<int,int>>::iterator it;
    for(it=v_p.begin();it!=v_p.end();++it){
         cout<<it->first<<" "<<it->second<<endl;
    }
    /*
    range based loop
    for(int value:v){
        cout<<value<<" ";
    }
    cout << endl;*/ 
    vector<pair<int,int>>hello={{1,2},{3,4}};
    for(auto&value:hello){
        cout<<value.first<<" "<<value.second;
    }

    auto a=1.0;
    cout<<a<<endl; // auto replaces pair<int,int>
}