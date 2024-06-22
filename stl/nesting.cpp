#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;
int main()
{
    map<pair<string, string>, vector<int>> m;
    pair<int, int> p1, p2;

    int num_of_students;
    cin >> num_of_students;
    
    for (int i = 0; i < num_of_students; ++i)
    {
        string first_name, last_name;
        
        // number of marks inputting...
        int ct;
        cin >> first_name >> last_name >> ct;
        for (int j = 0; j < ct; ++j)
        {
            int x;
            cin >> x;
            m[{first_name, last_name}].push_back(x);
        }
    }

    for (auto &pr : m)
    {
        auto &ful_nam = pr.first;
        auto &list = pr.second;
        cout << ful_nam.first << " " << ful_nam.second << endl;
        cout << list.size() << endl;
        for (auto &element : list)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}
