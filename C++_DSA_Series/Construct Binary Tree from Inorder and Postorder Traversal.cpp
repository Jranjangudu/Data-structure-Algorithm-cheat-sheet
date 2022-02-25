// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// https://www.youtube.com/watch?v=ffE1xj51EBQ
class Solution {
    private:
    void nodeToIndexMap(vector<int>& in , map<int,int>&nodeToIndex , int n){
        for(int i = 0 ; i < n ; i++){
           nodeToIndex[in[i]] = i;
        }
    }
    
    TreeNode * solve(vector<int>& in, vector<int>& post, int &index ,map<int ,int >&nodeToIndex ,int inOrderStartIdx ,int inOrderEndIdx ,int n ){
         
        // base case
        if(index < 0 || inOrderStartIdx > inOrderEndIdx ){
            return NULL;
        }
        // create a node
        int element = post[index--];
        TreeNode * root = new TreeNode(element);
        // find element
        int position = nodeToIndex[element];
       
        // in case of Postorder and Inorder , we call first right part then left part
        root->right = solve(in , post , index , nodeToIndex, position+1 , inOrderEndIdx, n);
        root->left = solve(in , post , index ,nodeToIndex, inOrderStartIdx , position-1 , n);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = postorder.size();
        int postOrdIndex = n-1;
        map<int , int>nodeToIndex;
        nodeToIndexMap(inorder , nodeToIndex , n);
        TreeNode* ans = solve(inorder ,postorder , postOrdIndex , nodeToIndex, 0 , n-1 , n);
        return ans;
    }
};// Time Complexity: O(Nlogn) { for map = O(logN) * for recursion call = O(N)}
//  Auxiliary Space: O(N).