i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
          size--;
          if(arr[j]<arr[i]){
            swap(arr[j],arr[i]);
          }
          i--;
        }
    }
}
int main(){
   int size;
   cout<<"Enter the size of the array: ";
   cin>>size;
   int arr[size];
   for(int i=0;i<size;i++){