#include <iostream>
using namespace std;


void bubbleSort(int* arr , int size){
  //base case - already sorted
  if(size == 0 || size == 1){
    return ;
  }
  //1 case sovle karlia - largest element ko end me rakh dega
  for(int i = 0  ; i < size-1 ; i++){
    if(arr[i] > arr[i+1]){
      swap(arr[i] , arr[i+1]);
    }
  }
  //base case - already sorted
  bubbleSort(arr, size-1);
  
}

int main() {

  // bubble sort using recursion
  int arr[5] ={12,6,1,7,0};
  bubbleSort(arr,5) ;
  // after sorting
  for(int i =0 ;  i < 5 ; i++){
    cout << arr[i] << " " ;
  }
} 