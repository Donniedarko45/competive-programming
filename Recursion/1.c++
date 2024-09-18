#include<iostream>
using namespace std;
void revNum(int n){
    if(n<1){
       return;
    } else{
        cout<<n;
        n--;
        revNum(n);
    }
}
//parametrised way
void sumOfN(int n,int sum){
  if(n<1){
    cout<<sum;
    return;
  }else{
    sumOfN(n-1,sum+n);
  }
}

//functional way...
int factOfN(int n){
    if(n==0){
        return 1;
    }else{
      return n*factOfN(n-1);
    }
}

int main(){
    int n;
    cin>>n;
   // revNum(n);
  // sumOfN(n,0);
   cout<<(factOfN(n));
}