#include<bits/stdc++.h>
using namespace std;

int missingNumber(int arr[],int n){
   int hash[n+1]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(hash[i]==0){
            cout<<"missing number is: "<<i;
        }
    }
}

int optimalMissingNumber(int arr[],int n){
    //by XOR
    int xor1,xor2=0;
    for(int i=0;i<n-1;i++){
        xor1=xor1^(i+1);
        xor2=xor2^arr[i];
    }
    xor1=xor1^n;
    int missingNum=xor1^xor2;
    cout<<"Missing number is: "<<missingNum;
}  
int main(){
    int arr[5]={1,2,3,4};
    optimalMissingNumber(arr,5);
    missingNumber(arr,5);
}