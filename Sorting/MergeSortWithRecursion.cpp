void merge(vector < int > & arr , int s , int e){
    int mid = s + (e - s)/2;
    int len1 = mid-s+1;
    int len2 = e - mid;
    // Dynamic memory declairation
    int *firstArray = new int[len1];
    int *secondArray = new int[len2];
    
    
    int index =s;
    for(int i = 0 ; i < len1 ; i++){
        firstArray[i] = arr[index++];
    }
    index = mid+1;
     for(int i = 0 ; i < len2 ; i++){
        secondArray[i] = arr[index++];
    }
    
    // merge two array
    int index1 = 0;
    int index2 = 0;
    index = s;
    while(index1 < len1 && index2 < len2){
        if(firstArray[index1] <= secondArray[index2]){
            arr[index++] = firstArray[index1++];
        }
        else{
            arr[index++] = secondArray[index2++];
        }
    }
    
    while(index1 < len1){
        arr[index++] = firstArray[index1++];
    }
    while(index2 < len2){
        arr[index++] = secondArray[index2++];
    }
    
    // it is important to delete the dynamic memory;
    // memory free
    delete []firstArray;
    delete []secondArray;
}

void mergeSorting(vector < int > & arr , int s , int e ){
    if(s >= e){
        return ;
    }
    int mid = s + (e - s)/2;
    
    // left part calling
    mergeSorting(arr,s,mid);
    
    // right part calling
    mergeSorting(arr,mid+1 , e);
    
    // finaly merge two array;
    
    merge(arr, s, e);
}

void mergeSort(vector < int > & arr, int n) {
    mergeSorting(arr,0,n-1);
   
}