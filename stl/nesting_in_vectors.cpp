#include<bits/stdc++.h>
using namespace std;

void printVec(vector<pair<int,int>> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}

/*int main(){ 
    vector<pair<int,int>>v={{1,2},{2,3},{4,5}};
    printVec(v);
}*/
// by user
int main(){
    vector<pair<int,int>>v;
    int n;
    cout<<"enter how many value pair do you want: ";
    cin>>n;
    int i;
    for(i=0;i<n;++i){
        int x,y;
        cout<<"enter pair "<<i+1<<" ";
        cin>>x>>y;
        v.push_back({x,y}); // another syntax v.push_back(make_pair(x,y));
    }
    printVec(v);
}