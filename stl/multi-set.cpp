#include <bits/stdc++.h>
using namespace std;

void print(multiset<string> &s)
{
    for (string value : s) {
        cout << value << endl;
    }

    for (auto it = s.begin(); it != s.end(); ++it)
    {
        cout << (*it) << endl;
    }
}
int main()
{
    //multiple same element allowed hota hai
    multiset<string> s;
    s.insert("abc"); // O(log(n))
    s.insert("bcd");
    s.insert("hello");
    s.insert("abc");
    // for deleting only one element

    auto it = s.find("abc");  // O(log(n))
    if(it!=s.end()){
       // s.erase(it);
    }
    // for deleting both elememnt
    s.erase("abc");
    print(s);
}