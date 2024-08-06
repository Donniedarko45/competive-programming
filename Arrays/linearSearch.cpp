#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>a,int num){
         for(int i=0;i<a.size();i++){
        if(a[i]==num){
            cout<<"Element is present at: "<<i<<"th index";
            break;
        }
    }
}

int main(){
    vector<int>a;
    a={1,2,3,4,5,6,7};
    int num;
    cin>>num;
   linearSearch(a,num);
}