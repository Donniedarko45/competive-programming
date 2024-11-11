#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    int temp=n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<j+1;
        }
        for(int k=0;k<2*(temp-1);k++){
            cout<<" ";  
        }
        temp--;
        for(int l=i;l>=0;l--){
            cout<<l+1;
        }
        cout<<endl;
    }
}

void pattern2(int n){
    int temp=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<temp<<" ";
            temp++;
        }
        cout<<endl;
    }
}

void pattern3(int n){
    for(int i=0;i<n;i++){
        for(char j='A';j<='A'+i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void pattern4(int n){
    for(int i=0;i<n;i++){
        for(char ch='A';ch<='A'+(n-i-1);ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void pattern5(int n){
    for(int i=0;i<n;i++){
        char ch='A'+i;
        for(int j=0;j<=i;j++){
            cout<<ch;
        }
        cout<<endl;
    }
}

void pattern6(int n){
    for(int i=0;i<n;i++){
      char ch='A';
      int breakpoint=(2*i+1)/2;
      for(int j=0;j<=n-i-1;j++){
        cout<<" ";
      }
       for(int l=0;l<2*i+1;l++){
        cout<<ch;
        if(l<breakpoint) ch++;
        else ch--;
       }

      for(int k=0;k<=n-i-1;k++){
        cout<<" ";
      }
      cout<<endl;
    }
}

void pattern7(int n){
    for(int i=0;i<n;i++){
        char ch='E'-i;
        char temp=ch;
        ch=ch-i;
        for(int j=0;j<=i;j++){
            cout<<temp;
            temp++;
        }
        
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    pattern7(n);  
    
}