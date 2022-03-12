class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // space complexity O(N) to O(1) using inorder traversal with  morris traversal !
        vector<int> inorder;
        TreeNode* curr = root;
        while(curr !=  NULL){
            if(curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                  TreeNode*prev =curr->left;
                    // get predecessor
                    while(prev->right != NULL && prev->right != curr){
                        prev = prev->right;
                    }
                    
                    if(prev->right == NULL){
                        prev->right = curr;
                        curr = curr->left;
                    }else{
                        prev->right = NULL;
                        inorder.push_back(curr->val);
                        curr = curr->right;
                    }
                
            }
        }
        
        return inorder;
    }
}