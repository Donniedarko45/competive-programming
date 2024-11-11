#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<string>q;
    q.push("cde");
    q.push("gft");
    q.push("mop");
    q.push("lop");
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}
