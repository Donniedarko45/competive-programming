#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i]; 
    }
    cout<<endl;
    sort(a,a+n);
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int *ptr=lower_bound(a,a+n,45);
    cout<<&a[3];
    cout<<(*ptr)<<endl;
}