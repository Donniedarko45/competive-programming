/*check if a string is pallindrome or not  >> we can do this by double pointer*/

#include <bits/stdc++.h>
using namespace std;
bool fxnToCheckPallindrome(int i, string &s) {
  if (i >= s.size() / 2)
    return true;
  if (s[i] != s[s.size() - i - 1])
    return false;
  return fxnToCheckPallindrome(i + 1, s);
}

int main() {
  string s = "madam";
  cout << "entered string is: " << fxnToCheckPallindrome(0, s);
  return 0;
}
