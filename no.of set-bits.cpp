#include<bits/stdc++.h>
using namespace std;
int main(){
    int start,goal;
    cout<<"Enter number 1: ";
    cin>>start;
    cout<<"Enter number 2: ";
    cin>>goal;
    int out=start^goal;
    //*now counting no of set bits..
    int count=0;
    while(out!=0){
        out=out&out-1;
        count++;
    }
    cout<<"no. flips required is: "<<count;

}