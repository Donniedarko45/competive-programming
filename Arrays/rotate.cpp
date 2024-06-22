// left rotate an element by one place..

#include<bits/stdc++.h>
using namespace std;

/*
*input:- arr[]=[1,2,3,4,5]
*output:-arr[]=[2,3,4,5,1] */

int ArrayRotationByOnePlace(int arr[],int n){
    int temp=arr[0];
    for(int i=0;i<n;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
    for(int i =0;i<=n;i++){
        cout<<arr[i];
    }
}

int main(){
    int n;
    cout<<"enter how many elements do you want in your arr: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ArrayRotationByOnePlace(arr,n);
}

