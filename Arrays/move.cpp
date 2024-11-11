/* move all zero at the end of the array */
#include<bits/stdc++.h>
using namespace std;

// brute method
int zeroElement(vector<int>arr,int n){
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    int noOfZeroes = n-temp.size();  // to calculate no of zeroes in vector arr
    for(int i=0;i<temp.size();i++){
        arr[i]=temp[i];
    }
    for(int i=temp.size();i<n;i++){
       arr[i]=0;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//optimal solution 

int moveZero(vector<int>arr,int n){
/*two pointer approach*/ 
    int i,j;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }

    for(int i=j+1;i<n;i++){
       if(arr[i]!=0){
        swap(arr[i],arr[j]);
        j++;
       }
    }
}

int main(){
    int n;
    cout<<"Enter how many elements do you want in your array: ";
    cin>>n;
    vector<int>arr;
    int element;
    for(int i=0;i<n;i++){
       cin>>element;
       arr.push_back(element);
    }
    zeroElement(arr,n);
}