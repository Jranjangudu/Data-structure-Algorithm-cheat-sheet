// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1/#
// TC = O(N)
// SC = O(N)
Node* solve(Node *root, int &k, int node){
    
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == node){
        return root;
    }
    
    Node* leftAns = solve(root->left , k , node);
    Node* rightAns = solve(root->right , k , node);
    
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k == 0){
            
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k == 0){
           
            return root;
        }
        return rightAns;
    }
    else{
        return NULL;
    }
}
int kthAncestor(Node *root, int k, int node)
{
   Node* ans = solve(root , k , node);
   
   if(ans == NULL || ans->data == node)
    return -1;
    
   else
    return ans->data;
}
