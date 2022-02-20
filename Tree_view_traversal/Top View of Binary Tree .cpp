// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1/#
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
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
            
            // if one value is present for a hd , then do nothing
            // if not found the mapping key , is equal to myMap.end() 
            if(myMap.find(hd) == myMap.end()){ // it means not value present in map
                myMap[hd] = frontNode->data;
            }
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
Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100

Output: 40 20 10 30 100