// sub-sequence==> a contigous/non-contigous sequence which follows the order {a subarray or empty array can be sequence} in a array lets say an array has [3,1,2] than 3,2,1 cant be in sub-sequence u have because 2 pehle nahi hai 1 ke array me

// TODOs do handwritten recursion calls helps in better understanding I have taken screenshot if any help 

#include<bits/stdc++.h>
using namespace std;
void subSequence(int ind,vector<int>&ds,int arr[],int n){
    if(ind==n){
        for(auto it : ds){
          cout<<it<<" ";
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    // take or pick the particular index into the sub-sequence
    ds.push_back(arr[ind]);
    subSequence(ind+1,ds,arr,n);
    ds.pop_back();

    // not picking or not take condition,this element is not added to your sub sequence
    subSequence(ind+1,ds,arr,n);
}
int main(){
 int arr[]={3,1,2};
 int n=3;
 vector<int>ds;
 subSequence(0,ds,arr,n);
}
// time-complexity => O(2^n*n)  space-complexity=> O(n)