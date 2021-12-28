// https://leetcode.com/problems/search-a-2d-matrix-ii/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col =matrix[0].size();
        
        int start = 0;
        int end = col-1;
        
        while(start < row && end >= 0){
            int element = matrix[start][end];
            if(element == target)
                return true;
            if(element > target){
                end--;
            }
           else{
               start++;
           }
        }
        return false;
        
    }
};
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true