// https://www.youtube.com/watch?v=OyZFFqQtu98
// https://leetcode.com/problems/combination-sum/
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
class Solution {
private:
    void findCombination(int index , int target ,vector<int>& arr , vector<int>&ds ,vector<vector<int>>& ans){
        // base case
        if(index == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        
        // pick element
        int curr = arr[index];
        if(curr <= target){
            ds.push_back(curr);
            findCombination(index , target - curr , arr , ds , ans);
            // backtrack--> make sure pop the last element
            ds.pop_back();
        }
        // not pick element;
        findCombination(index+1 , target , arr , ds , ans);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        int index = 0;
        findCombination(index , target , candidates, ds , ans);
        return ans;
    }
};// TC == O(2^t * k)