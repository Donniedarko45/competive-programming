#include<bits/stdc++.h>
using namespace std;
// brute force method..
int largest_element(int arr[],int size){
    //let highest element would be.... 
    int max= arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<"Highest element would be: "<<max;
}

int second_largest(int arr[],int size){
    // brute force=>sort the array then largest=arr[n-1] now compare it with arr[n-2] if both are different then second largest would be that element..

    sort(arr,arr+size);
    int largest=arr[size-1];
    int second_largest;
    for(int i=size-2;i>=0;i--){
        second_largest=arr[size-2];
        if(largest!=second_largest){
            second_largest=arr[i];
            break;
        }
      }
     cout<<"Second Highest element would be: "<<second_largest;
}

// second largest :-better solution...

int better_second_largest(int arr[],int size){
    int second_largest=INT_MIN;
    int largest=INT_MIN;
    // first we have to find largest element than compare it with second largest

    for(int i=0;i<size;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    // now code for second largest...
    for(int i=0;i<size;i++){
        if(arr[i]>second_largest && arr[i]!=largest){
            second_largest=arr[i];
        }
    }

    cout<<"Second largest element is: "<<second_largest;
}


int main(){
   int size;
   cin>>size;
   int arr[size];
   cout<<"Enter the elements in the array: "<<endl;
   for(int i=0;i<size;i++){
    cin>>arr[i];
   }
   better_second_largest(arr,size);
   return 0;
}