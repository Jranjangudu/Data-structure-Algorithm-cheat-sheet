// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
class Solution {
public:
    bool check(vector<int>& nums) {
        int count =0; 
        for(int i =1 ; i < nums.size() ; i++){
            if(nums[i] < nums[i-1]){
                count++;
            }
        }
        int n = nums.size()-1;
        // compair fast and last number;
        if(nums[0] < nums[n]){
            count++;
        }
        
        return count <=1 ;
    }
};