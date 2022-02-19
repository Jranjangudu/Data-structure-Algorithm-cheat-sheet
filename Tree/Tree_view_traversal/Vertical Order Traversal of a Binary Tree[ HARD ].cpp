https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
https://www.youtube.com/watch?v=s1d8UGDCCN8&t=3276s
https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1#
https://media.geeksforgeeks.org/img-practice/ScreenShot2021-05-28at3-1622541589.png
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int , map<int , vector<int> > >nodes;
        
        queue<pair<TreeNode* , pair<int,int> > > q;
        
        vector<vector<int>> ans;
        
        if(root == NULL){
            return ans;
        }
        
        q.push(make_pair(root ,make_pair(0 , 0)));
        
        while(!q.empty()){
            pair<TreeNode* , pair<int,int> > temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int horDist = temp.second.first;
            int level =  temp.second.second;
            
            nodes[horDist][level].push_back(frontNode->val) ;
            if(frontNode->left){
                q.push(make_pair(frontNode->left , make_pair(horDist-1 , level+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right , make_pair(horDist+1 , level+1)));
            }
        }
        
        // retrive map data
          for (auto i : nodes) {
            vector<int> col;
            for (auto j : i.second) {
                // j.second --> contain a vector
                sort(begin(j.second), end(j.second));
                for(auto k : j.second){
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};
   

