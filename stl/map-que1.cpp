/*
 given N strings,print unique strings in lexographical order={increasing order} with their frequency
 N<=10^5
 |S|<=100
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        m[s] = m[s] + 1; /*For each input string s, the program inserts it into the map m using m[s]++. If s is already present as a key in the map, its associated value (the frequency) is incremented. If s is not present, a new key-value pair is added to the map with s as the key and the value 1 as its initial frequency.

             So, the map itself ensures that each input string is checked for whether it already exists as a key, and if so, its frequency is incremented accordingly. If it doesn't exist, a new key-value pair is added automatically.*/
    }

    // printing..{here in this map key is string and value is frequency}
    for (auto pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}