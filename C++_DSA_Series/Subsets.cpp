// https://leetcode.com/problems/subsets/
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


class Solution {
private:
    void solve(vector<int> nums , vector<int> output , vector<vector<int>>&ans , int index){
        
        // base case
        if(index >= nums.size()){
            // before returing you must store the output value;
            ans.push_back(output);
            return;
        }
        
        // exclude call------------
        solve(nums , output , ans , index+1);
        
        // include call---------
        // in clude call , first add the index value in output array then call the solve func
        
        int element = nums[index];
        output.push_back(element);
        solve(nums , output , ans , index+1);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        
        solve(nums , output , ans , index);
        
        return ans;
        
    }
};