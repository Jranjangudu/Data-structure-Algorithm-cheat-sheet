#include<iostream>
using namespace std;
int partition( int arr[], int s, int e) {

    int pivot = arr[s];

    int count = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            count++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);
    // / now check the laft and right part of pivot value
    //left and right wala part smbhal lete h 
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    //base case
    if(s >= e) 
        return ;
     // find pivot element index
    //partitioon karende
    int p = partition(arr, s, e);

    //left part sort karo
    quickSort(arr, s, p-1);

    //right wala part sort karo
    quickSort(arr, p+1, e);
}
int main() {
    int arr[10] = {2,4,1,6,9 ,9,9,9,9,9};
    int n = 10;
    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;
    return 0;
}


// -------------------------------------------------------------------
// *************************************************************

int partition(vector <int> &arr , int s , int e){
    int pivot = arr[s];
    int count = 0;
    for(int i = s+1 ; i <= e ; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    int pivotIndex =  s + count;
    // place the pivot value to the right position
    swap(arr[pivotIndex] , arr[s]);
    // now check the laft and right part of pivot value
    int i = s;
    int j = e;
    
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= arr[pivotIndex]){
            i++;
        }
        while(arr[j] > arr[pivotIndex]){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++] , arr[j--]);
        }
    }
    return pivotIndex;
}

void solveQuickSort(vector <int> &arr , int s , int e){
    // base case
    if(s >= e){
        return;
    }
    
    // find pivot element index
    int p = partition(arr ,s , e);
    
    // left part sort karo
    solveQuickSort(arr , s , p-1);
    // right part sort karo
    solveQuickSort(arr , p+1 ,e);
}

vector<int> quickSort(vector<int> arr)
{
    solveQuickSort(arr,0,arr.size()-1);
    return arr;
}
