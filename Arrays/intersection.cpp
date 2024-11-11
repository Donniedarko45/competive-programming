#include<bits/stdc++.h>
using namespace std;

int intersectionOfArray(int a1[],int a2[],int size1,int size2){
    vector<int>combine;
    int visible[size2]={0};
    for(int i=0;i<size1;i++){
      for(int j=0;j<size2;j++){
         if(a1[i]==a2[j] && visible[j]==0){
            combine.push_back(a1[i]);
            visible[j]=1;
            break;
         }
         if(a2[j]>a1[i]) break;
      }
    }
}

int optimalIntersectionofArray(int a1[],int a2[],int size1,int size2){
  int i=0;
  int j=0;
  vector<int>combine;
  while(i<size1 && j<size2){
   if(a1[i]<a2[j]){
      i++;
   }
   else if(a2[j]<a1[i]){
      j++;
   }
   else{
      combine.push_back(a1[i]);
      i++;
      j++;
   }
  } 
}

int main(){
  int size1, size2;
   cout << "Enter the size of array1: ";
   cin >> size1;
   cout << "Enter the size of array2: ";
   cin>>size2;
   int a1[size1], a2[size2];
   int num;
   for(int i=0;i<size1;i++){
      cin>>a1[i];
   }
   for(int i=0;i<size2;i++){
      cin>>a2[i];
   }
   intersectionOfArray(a1, a2, size1, size2);
}
