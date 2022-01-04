#include <iostream>
using namespace std;

bool foundKey(int * arr , int s , int k){

  if(s == 0)
    return false;

  if(arr[0] == k)
    return true;

  return foundKey(arr+1 , s-1,k);

}
int main() {

 int arr[5] ={2,5,7,3,4};
 int size = 5;
 int key = 71;
 // liner search 
 bool ans =foundKey(arr,size , key);
if(ans){
  cout << "key found" << endl;
}else{
  cout << "Key not found " << endl;
}
    return 0;
} 