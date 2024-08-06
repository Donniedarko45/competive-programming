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


/*left rotate an element by D places*/

//brute force method..
int leftRotateElementBrute(int arr[],int n){
    int d;
    d=d%n;
    cout<<"Enter how many elements do you want to left rotate: ";
    cin>>d;
    int temp[d];
    //suppose I have to left rotate 4 elements than I have to store first four elements in an array
    for(int i=0;i<d;i++){
         temp[i]=arr[i];
    }
   
   // rotating..
   for(int i=d;i<n;i++){
    arr[i-d]=arr[i];
   }
   int j=0;
   for(int i=d;i<n;i++){
    arr[i]=temp[j];
    j++;
   }
   cout<<"Array printing: ";
   for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int leftRotateElementBetter(int arr[],int n){
    //jst same but j ko use nai krenge more abt extra space

     int d;
    d=d%n;
    cout<<"Enter how many elements do you want to left rotate: ";
    cin>>d;
    int temp[d];
    for(int i=0;i<d;i++){
         temp[i]=arr[i];
    }
   
   // rotating..
   for(int i=d;i<n;i++){
    arr[i-d]=arr[i];
   }

   for(int i=n-d;i<n;i++){
    arr[i]=temp[i-(n-d)];
   }

   cout<<"Array printing: ";
   for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int leftRotateElementOptimal(int arr[],int n){
     int d;
     cout<<"Enter how many elements do you want to left rotate: ";
     cin>>d;
     //first we have to reverse 0 th index to dth index element than d th to n-1 th index element than reverse an whole array
     reverse(arr,arr+d);
     reverse(arr+d,arr+n);
     reverse(arr,arr+n); // here we got resultant array


}


int main(){
    int n;
    cout<<"enter how many elements do you want in your arr: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //ArrayRotationByOnePlace(arr,n);
    leftRotateElementBrute(arr,n);
}

