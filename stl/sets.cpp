#include <bits/stdc++.h>
using namespace std;

// in programming sets represent collection of some elements unique elememnt ko store krta hai
void print(set<string> &s)
{
    for (string value : s) // for auto value in s
    {
        cout << value << endl;
    }
    // another way of printing..

    for (auto it = s.begin(); it != s.end(); ++it)
    {
        cout << (*it) << endl;
    }
}
int main()
{
    set<string> s;
    s.insert("abc"); // log(n)
    s.insert("bcd");
    s.insert("hello");
    auto it = s.find("abc");  // O(log(n))
    if(it!=s.end()){
        s.erase(it);
    }
    print(s);
}