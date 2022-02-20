https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1/#
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int , int > myMap;
        queue<pair<int , Node*> >q;
        vector<int>ans;
        
        if(root == NULL){
            return ans;
        }
        q.push(make_pair(0 , root));
        
        while(!q.empty()){
            pair<int , Node*> temp = q.front();
            q.pop();
            Node* frontNode = temp.second;
            int hd = temp.first; // hd == horizental distance
            
          // just update hd corresponding value
            myMap[hd] = frontNode->data;
            
            if(frontNode->left){
                q.push(make_pair(hd-1 ,frontNode->left ));
            }
             if(frontNode->right){
                q.push(make_pair(hd+1 ,frontNode->right ));
            }
        }
        for(auto i : myMap){
            ans.push_back(i.second);
        }
        return ans;
    }
};