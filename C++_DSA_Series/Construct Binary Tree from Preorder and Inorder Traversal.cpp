// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// https://www.youtube.com/watch?v=ffE1xj51EBQ
class Solution {
private:
    void nodeToIndexMap(vector<int>& in , map<int,int>&nodeToIndex , int n){
        for(int i = 0 ; i < n ; i++){
           nodeToIndex[in[i]] = i;
        }
    }
    
    TreeNode * solve(vector<int>& in,vector<int>& pre, int &index ,
                     map<int ,int >&nodeToIndex ,int inOrderStartIdx ,int inOrderEndIdx ,int n ){
        // base case
        if(index >= n ||inOrderStartIdx > inOrderEndIdx ){
            return NULL;
        }
        // create a node
        int element = pre[index++];
        TreeNode * root = new TreeNode(element);
        // find element
        int position = nodeToIndex[element];
        
        root->left = solve(in , pre , index ,nodeToIndex, inOrderStartIdx , position-1 , n);
        root->right = solve(in , pre , index , nodeToIndex, position+1 , inOrderEndIdx, n);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        int inOrdIndex = 0;
        map<int , int>nodeToIndex;
        nodeToIndexMap(inorder , nodeToIndex , n);
        TreeNode* ans = solve(inorder ,preorder , inOrdIndex , nodeToIndex, 0 , n-1 , n);
        return ans;
    }
};
// Time Complexity: O(Nlogn) { for map = O(logN) * for recursion call = O(N)}
//  Auxiliary Space: O(N).