// https://leetcode.com/problems/permutations/
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

class Solution {
private:
    void solve(vector<int>nums , int index , vector<vector<int>> & ans){
        // base case
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i = index ; i < nums.size() ; i++){
            swap(nums[i] , nums[index]);
            // Recursive call
            solve(nums , index+1 , ans);
            // Backtracking
            swap(nums[i] , nums[index]);
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int index=  0;
        
        solve(nums , index , ans );
        return ans;
        
    }
};