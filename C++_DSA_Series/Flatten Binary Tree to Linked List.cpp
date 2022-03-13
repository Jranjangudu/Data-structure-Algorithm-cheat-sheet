class Solution {
    public:
    void flatten(TreeNode* root) {  // TC = O(N) , // SC = O(1) in-place
        TreeNode * curr = root;
        // USING MORRIS TRAVERSAL
        while(curr != NULL){
            if(curr->left){
                TreeNode* prev = curr->left;
                 // get predecessor
                while(prev->right != NULL){
                    prev = prev->right;
                }
                // connect prev->right link to curr->right node
                prev->right = curr->right;
                // cut the curr->right link to curr->left
                curr->right = curr->left;
                // now point curr->left to null;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
    
};