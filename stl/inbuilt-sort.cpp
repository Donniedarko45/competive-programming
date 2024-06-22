#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
sort(a,a+n); //(start,end) jahan se sorting suru krni hai pehle aur dusra iz jahan tak krni hai usse ekk aage
for(int i=0;i<n;++i){
    cout<<a[i]<<endl;
}
}

/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
sort(a.begin(),a.end()); 
for(int i=0;i<n;++i){
    cout<<a[i]<<endl;
}
}
*/