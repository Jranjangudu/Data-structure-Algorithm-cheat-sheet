https://leetcode.com/problems/check-completeness-of-a-binary-tree/
class Solution {
    // TC == O(N) + O(N) + O(N) ---> O(N)
    // SC = O(N)
private:
    int countNodes(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    bool isCBT(TreeNode* root , int i , int n){
        if(root == NULL){
            return true;
        }
        if(i >= n){
            return false;
        }
        else{
            bool left = isCBT(root->left , 2*i+1 , n);
            bool right = isCBT(root->right , 2*i +2 , n);
            return (left && right);
        }
    }
    bool isMinorder(TreeNode* root){
        if(root->left == NULL && root->right == NULL)
            return true;
        if(root->right == NULL){
            return root->val < root->left->val;
        }
        else{
            bool left = isMinorder(root->left);
            bool right = isMinorder(root->right);
            if(left && right && (root->val < root->left->val && root->val < root->right->val)){
                return true;
            }
            else{
                return false;
            }
        }
    }
   
public:
    bool isCompleteTree(TreeNode* root) {
        int index = 0;
        int totalCount = countNodes(root);
        
        if(isCBT(root , index , totalCount) && isMinorder(root)){
            return true;
        }
        return false;
    }
};
// CBT = complete binary tree