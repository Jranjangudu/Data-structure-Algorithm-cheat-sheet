// https://www.youtube.com/watch?v=9ZyLjjk536U
Input: nums = [0,1]
Output: 2
Input: nums = [0,1,0]
Output: 2

// TC = O(n) 
// SC = O(n) 
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       // create a unordered map;
        unordered_map<int , int> mymap;
        int sum = 0;
        int longest_subarray = 0;
        
        for(int i = 0 ; i  < nums.size() ; i++){
            // if nums[i] == 0 , then make it -1;
            sum += nums[i] == 0 ? -1 : 1;
            
            if(sum == 0){ // sum zero , that means from starting index to curr index is a contiguous subarray  
                if(longest_subarray < i +1){
                    longest_subarray = i +1;
                }
            }else{
                if(mymap.find(sum) != mymap.end()){ // if mymap contain the value
                    // map contain
                    if(longest_subarray < i - mymap[sum]){
                        longest_subarray = i - mymap[sum];
                    }
                }
                else{ // adding key value into mymap ,
                    mymap[sum] = i;
                }
            }
        }
        return longest_subarray;
    }
};