#include <bits/stdc++.h>
using namespace std;

int main() {
// when every character in a string is in lowercase..
    string s;
    cout<<"Enter a string: ";
    cin >> s;

    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++;
    }
    // now checking a which char occured how much times..
    int q;
    cout<<"Number of char do you want to check the occurence: ";
    cin >> q;
    while (q--) {
        char c;
        cout<<"Enter the character: ";
        cin >> c;
        cout << hash[c - 'a'] << endl;
    }
    return 0;
}