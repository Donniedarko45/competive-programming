#include<bits/stdc++.h>
using namespace std;

void print(unordered_map<int, string> &m)
{
    cout << m.size() << endl;
    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}

int main(){
  
  /*diff between ordered and unordered maps..
  1.inbuilt implementation
  2.time complexity
  3. valid keys data-types*/

   unordered_map<int, string> m;
    m[1] = "abc";  //O(1)
    m[4] = "cdc";
    m[2] = "acd";
    m.insert({3, "dac"});
    m[6]="hello";
    m[5]="a";
    
    print(m);
}