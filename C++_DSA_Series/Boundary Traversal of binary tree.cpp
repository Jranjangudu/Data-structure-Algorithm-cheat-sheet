// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/#
class Solution {
private:
void traverseLeft(Node *root, vector<int> & ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    };
    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left , ans);
    }
    else{
        traverseLeft(root->right , ans);
    }
}
void traverseLeaf(Node *root, vector<int> & ans){
    if(root == NULL){
        return;
    }
    if((root->left == NULL && root->right == NULL)){
        ans.push_back(root->data);
        return;
    };
    traverseLeaf(root->left , ans);
    traverseLeaf(root->right , ans);
    
}
void traverseRight(Node *root, vector<int> & ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    };
    if(root->right){
        traverseRight(root->right , ans);
    }else{
        traverseRight(root->left , ans);
    }
    ans.push_back(root->data);
}
public:
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root == NULL){
            return ans;
        }
        //left part print / store
        ans.push_back(root->data);
        // traverse left part
        traverseLeft(root->left , ans);
        
        // traverse leaf node
        // left subtree
        traverseLeaf(root->left , ans);
        // right subtree
        traverseLeaf(root->right , ans);
        
        // traverse right part
        traverseRight(root->right , ans);
        return ans;
    }
};
Input:                                           
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3
Input:
            1
           / 
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8
