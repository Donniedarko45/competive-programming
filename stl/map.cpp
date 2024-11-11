#include <bits/stdc++.h>
using namespace std;

// printing it by auto keyword..
void print(map<int, string> &m)
{
    cout << m.size() << endl;
    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}

int main()
{
    map<int, string> m;
    m[1] = "abc"; /* O(log(n))->insertion ki time complexity suppose the key is abcd or we can say m["abcd"]="defgh" than insertion complexity is {m.size()*log(n)}*/
    m[4] = "cdc";
    m[2] = "acd";
    // another way of initialsiation..
    m.insert({3, "dac"});
    map<int, string>::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }

    // fxn calling to print map...
    print(m);

    auto pct = m.find(2); // O(log(n))=>searching
    if (pct == m.end())
    {
        cout << "No value";
    }
    else
    {
        cout << (*pct).first << " " << (*pct).second;
    }

    // for clearing the map we use m.clear
}