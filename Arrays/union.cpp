#include <bits/stdc++.h>
using namespace std;
// brute force
int unionSet(int a1[], int a2[], int size1, int size2)
{
   set<int> combine;
   int count = 0;
   for (int i = 0; i < size1; i++)
   {
      combine.insert(a1[i]);
      count++;
   }

   for (int i = 0; i < size2; i++)
   {
      combine.insert(a2[i]);
      count++;
   }
   cout<<"printing union: ";
   for(auto it:combine){
      cout<<it<<" ";
   }
}


//optimal approach

int optimalApproach(int a1[],int a2[],int size1,int size2){
   int i=0;
   int j=0;
   vector<int>unionArr;
   while(i<size1 && j<size2){
      if(a1[i]<=a2[j]){
         if(unionArr.size()==0||unionArr.back()!=a1[i]){
            unionArr.push_back(a1[i]);
         }
         i++;
      }
      else{
         if(unionArr.size()==0 || unionArr.back()!=a2[j]){
            unionArr.push_back(a2[j]);
         }
         j++;
      }
   }
   while(j<size2){
       if(unionArr.size()==0 || unionArr.back()!=a2[j]){
            unionArr.push_back(a2[j]);
         }
         j++;
   }
   while(i<size1){
      if(a1[i]<=a2[j]){
         if(unionArr.size()==0 || unionArr.back()!=a1[i]){
            unionArr.push_back(a1[i]);
         }
         i++;
   }

}
}


int main()
{
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
   unionSet(a1, a2, size1, size2);
}