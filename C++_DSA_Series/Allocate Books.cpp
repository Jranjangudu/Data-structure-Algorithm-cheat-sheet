// using binary search
bool isPossible(vector<int> arr, int n, int m , int mid){
    int student = 1;
    int booksum = 0;
    
    for(int i = 0 ; i < n ; i++){
        if(booksum + arr[i] <= mid){
            booksum +=arr[i];
        }
        else{
            student++;
            if(student > m || arr[i] > mid ){
                return false;
            }
            booksum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    // Write your code here.
    int s = 0;
    int sum = 0;
    
    // find sum of all number;
    for(int i = 0 ; i< n ; i++){
        sum +=arr[i];
    }
    int e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e){
        if(isPossible(arr,n,m,mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s  =  mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}