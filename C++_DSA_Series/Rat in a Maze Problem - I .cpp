// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR

// ---------------------


class Solution{
    private:
        bool isSafe(vector<vector<int>> &m, int n, int x , int y , vector<vector<int>> visited ){
            if((x >=0 && x < n) && (y >=0 && y < n) && m[x][y] == 1 && visited[x][y] == 0){
                return true;
            }
            else{
                return false;
            }
        
        }
    void solve(vector<vector<int>> &m, int n, string path , int srcx , int srcy , vector<string>&ans,vector<vector<int>> visited ){
        
        // base case
        
        if(srcx == n-1 && srcy == n-1){
            ans.push_back(path);
            return;
            
        }
        visited[srcx][srcy] = 1;
        // dowm
        int newx = srcx+1;
        int newy = srcy;
        if(isSafe(m , n , newx , newy , visited)){
            path.push_back('D');
            solve(m , n , path , newx , newy  , ans, visited );
            path.pop_back();
        }
        // left
        newx = srcx;
        newy = srcy-1;
        if(isSafe(m , n , newx , newy , visited)){
            path.push_back('L');
              solve(m , n , path , newx , newy  , ans, visited );
            path.pop_back();
        }
        // right
        newx = srcx;
        newy = srcy+1;
        if(isSafe(m , n , newx , newy , visited)){
            path.push_back('R');
               solve(m , n , path , newx , newy  , ans, visited );
            path.pop_back();
        }
        
        // up
        newx = srcx-1;
        newy = srcy;
        if(isSafe(m , n , newx , newy , visited)){
            path.push_back('U');
             solve(m , n , path , newx , newy  , ans, visited );
            path.pop_back();
        }
        visited[srcx][srcy] = 0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
        vector<vector<int>> visited=m;
        
        //edge case
        if(m[0][0] == 0){
            return ans;
        }
        
        int srcx = 0 ;
        int srcy = 0;
        string path = "";
        
        for(int i = 0 ; i  < n ; i++){
            for(int j = 0 ; j < n ; j++){
                visited[i][j] = 0;
            }
        }
        
        solve(m , n , path , srcx , srcy , ans , visited );
        sort(ans.begin() , ans.end());
        return ans;
    }
};

    