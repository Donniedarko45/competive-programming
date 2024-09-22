// fibonacci numbers ==> 0 1 1 2 3 5 8 13 21 34 .......

#include<bits/stdc++.h>
using namespace std;
int fibnocii(int n){
  if(n<=1) return n;
  int last=fibnocii(n-1);
  int slast=fibnocii(n-2);
  return last+slast;   
}
int main(){
  int n=5;
  cout<<"address of n inside a main fxn is: "<<(&n)<<endl;
  cout<<fibnocii(7);
  return 0;
}

// time complexity will be => near about O(2^n)