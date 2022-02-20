https://leetcode.com/problems/binary-tree-level-order-traversal/
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        queue<TreeNode*>q;
        if(root == NULL){
            return ans;
        }
        
        q.push(root);
        
        while(!q.empty()){
            int len = q.size();
            vector<int>curr(len);
            
            for(int i = 0 ; i  < len ; i++){
                TreeNode* temp = q.front();
                q.pop();
                curr[i] = temp->val;
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};

