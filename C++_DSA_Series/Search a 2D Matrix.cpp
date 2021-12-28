// https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search
        int row = matrix.size();
        int col = matrix[0].size();
        
        int s = 0 ; 
        int e = row * col - 1 ;
        int mid = s + (e-s)/2;
        
        while(s <= e){
            int element = matrix[mid/col][mid%col];
            
            if(element == target){
                return true;
            }
            if(element < target){
                s = mid +1;
            }
            else{
                e = mid -1;
            }
            mid = s + (e-s)/2;
        }
        return false;
    }
};

// time complecity O(log(mn)); 

// we know binary search complexity is O(logn)
//so here  { n = M * N }, or { row * col }

// so the complexity is  O(log(MN)); 


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true