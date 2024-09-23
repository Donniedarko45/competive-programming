/*
 *?selection sort=>select minimums
 ->get the minimum from the entire array wherever u find the min element swap the min num index to the first index and so on swap the next element with the ind+1
 ->then next minimum then next....
*/
#include<bits/stdc++.h>
using namespace std;
int SelectionSort(int arr[],int size){
   int minimum;
   for(int i=0;i<=size-2;i++){
     minimum=i;
     for(int j=i;j<=size-1;j++){
        if(arr[j]<arr[minimum]){
            minimum=j;
        }
     }
     int temp=arr[minimum];
     arr[minimum]=arr[i];
     arr[i]=temp;
   }
}
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<endl<<"Input the elements in an array: ";
    for(int i=0;i<size;i++){
     cin>>arr[i];
    }
    SelectionSort(arr,size);
    cout<<endl;
    cout<<"sorted array is: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// T.C=>O(n^2)
