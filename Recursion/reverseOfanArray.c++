#include <bits/stdc++.h>
using namespace std;
void reverseOfArray(int i, int arr[], int n) {
   cout<<"address of an array inside the fxn: "<<arr; // here also address is same means no duplicate array is made but there we havent pass with reference na than how does it changing the array => when you pass an array to fxn in a c/c++ you are actually passing a pointer to the first element of the array
   if (i >= n / 2) return; 
   swap(arr[i], arr[n - i - 1]); 
   reverseOfArray(i + 1, arr, n); 
}
int main() {
   int n;
   cin >> n; 
   int arr[n];
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   cout<<"address of arr before swapping is: "<<(arr)<<endl;
   reverseOfArray(0, arr, n);
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
   cout<<endl;
   cout<<"address of arr after swapping is: "<<(arr);
   cout << endl;
   return 0;
}
