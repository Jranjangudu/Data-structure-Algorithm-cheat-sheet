class Solution {
public:
    
    long long int binarySearch(int n){
        int s = 0;
        int e = n;
        long long int mid  = s + (e-s)/2;
        int ans = -1;
        
        while(s <= e){
            long long int squar = mid * mid;
            
            if(squar == n) 
                return mid;
            
            if(squar < n){
                s = mid+1;
                ans = mid;
            }
            else {
                e = mid-1;
            }
            mid  = s + (e-s)/2;
        }
        return ans;
        
    }
    int mySqrt(int x) {
        return binarySearch(x);
    }
};
// time complexity O(log n)