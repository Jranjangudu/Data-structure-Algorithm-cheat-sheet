// https://practice.geeksforgeeks.org/problems/sum-tree/1#

class Solution
{
    // TC = O(N);
    // SC = O(Height of the Tree)
    private:
    pair<bool , int > isSumTreeFast(Node* root){
        // base case
        if(root == NULL){
            pair<bool , int > p = make_pair(true , 0);
            return p;
        }
        // left node
        if(root->left == NULL && root->right == NULL){
            pair<bool , int > p = make_pair(true , root->data);
            return p;
        }
         pair<bool , int >left = isSumTreeFast(root->left);
         pair<bool , int >right = isSumTreeFast(root->right);
         
         bool leftAns = left.first;
         bool rightAns = right.first;
         
         bool comp = root->data == left.second + right.second;
         pair<bool , int >ans;
         
         if(leftAns && rightAns && comp){
             ans.first = true;
             ans.second = 2 * root->data; 
             // Or
            //   ans.second =  root->data +left.second + right.second ; 
         }else{
             ans.first = false;
         }
          
         return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }
};
Input:
    3
  /   \    
 1     2

Output: 1{true}
Input:

          10
        /    \
      20      30
    /   \ 
   10    10

Output: 0 {false}