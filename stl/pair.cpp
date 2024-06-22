#include<bits/stdc++.h>
using namespace std;
int main(){

    pair<int,string> p; // kinhi bhi doo data type ka pair bna skte hai and p iska naam hai

    p=make_pair(2,"abc"); // or another way of declaration p={2,"abc"}

    cout<<p.first<<" "<<p.second<< endl;
    
    int a[]={1,2,3};
    int b[]={4,5,6};
    pair<int,int> p_array[3];
    p_array[0]={1,4};
    p_array[1]={2,5};
    p_array[2]={3,6};

    swap(p_array[0],p_array[2]);
    
    for(int i=0;i<3;i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }
}