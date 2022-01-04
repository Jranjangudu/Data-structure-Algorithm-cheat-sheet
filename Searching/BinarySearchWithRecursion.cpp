#include <iostream>
using namespace std;

bool binarySearch(int* arr , int s,int e , int k){
  if(s < e){
    int mid = s + (e-s)/2;
    if(arr[mid] == k){
      return true;
    }
    else if(arr[mid] > k){
      return binarySearch(arr,s,mid-1,k);
    }
    return binarySearch(arr,mid+1,e,k);
  }
  return false;

}

int main() {
 int arr[5] ={2,3,5,7,8};
 int size = 5;
 int key = 17;
 int s = 0;
 int e = 4;
 bool ans =binarySearch(arr,s,e , key);
if(ans){
  cout << "key found" << endl;
}else{
  cout << "Key not found " << endl;
}
}