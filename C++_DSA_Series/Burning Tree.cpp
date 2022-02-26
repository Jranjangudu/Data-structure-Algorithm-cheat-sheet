 https://practice.geeksforgeeks.org/problems/burning-tree/1#
 https://www.youtube.com/watch?v=XLdpy0_6MR4
class Solution {
  private:
  Node * mapToParent(Node* root,  map<Node* ,Node*> &mapping ,int target){
      
      Node * targetNode = NULL;
      queue<Node*>q;
      q.push(root);
      mapping[root] = NULL;
      
      while(!q.empty()){
          Node* front = q.front();
          q.pop();
          
          if(front->data == target){
              targetNode = front;
          }
          
          if(front->left){
              mapping[front->left] = front;
              q.push(front->left);
          }
          if(front->right){
              mapping[front->right] = front;
              q.push(front->right);
          }
      }
      return targetNode;
  }
int burningTree(Node* root , map<Node* ,Node*> &mapping){
      
      map<Node*, bool>visited;
      queue<Node*>q;
      q.push(root);
      visited[root] = true;
      int burnItem = 0;
      
      while(!q.empty()){
          int size = q.size();
          bool flag = 0;
          for(int i = 0 ; i < size ; i++){
              Node * front = q.front();
              q.pop();
              
             if(front->left && !visited[front->left]){
                 q.push(front->left);
                 visited[front->left] = true;
                 flag = 1;
                 
             }
             if(front->right && !visited[front->right]){
                 q.push(front->right);
                 visited[front->right] = true;
                 flag = 1;
                 
             }
             Node* parentNode = mapping[front];
             if( parentNode && !visited[parentNode] ){
                 q.push(parentNode);
                 visited[parentNode] = true;
                 flag = 1;
             }
          }
          if(flag == 1){
              burnItem++;
          }
      }
      return burnItem;
      
  }
public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node* ,Node*> mapping; // this ,map store the current nodes, parent node
        Node* targetNode = mapToParent(root , mapping , target);
        int ans = burningTree(targetNode,mapping);
        return ans;
        
    } // TC = O(N log N)
      // SC = O(N)
};