#include <iosteam.h>
using namespace std;
int main() {
  int size;
  cin >> size;
  int arr[size];
  cout << "Enter a array: ";
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }
  cout << endl;
  // lets say highest number in an array can be 12 so we declare a hash array of
  // size 13;
  int hash[13] = {0};
  for (int i = 0; i < size; i++) {
    hash[arr[i]] += 1;
  }
  // now checking the how many times a number is in the arrray..
  int q;
  cin >> q;
  cout << "Checking how many times an num is existed: " << endl;
  while (q--) {
    int number;
    cin >> number;
    cout << hash[number] << endl;
    ;
  }
  return 0;
}
