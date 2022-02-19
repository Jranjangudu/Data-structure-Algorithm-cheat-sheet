// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
class Solution {
    // TC = O(N)
    // SC = O(N)
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        
        bool leftToRight = true;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            
            int len = q.size();
            vector<int>ans(len);
            // level process
            for(int i = 0 ; i  < len ; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                // normal insert or reverse insert
                int index = leftToRight ? i : len-i-1;
                ans[index] = temp->val;
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                
            }
            // direction change karni h
            leftToRight = !leftToRight; // true / false --> false / true
            
            result.push_back(ans);
        }
        return result;
    
    }
};