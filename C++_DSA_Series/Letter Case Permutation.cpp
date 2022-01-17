// https://leetcode.com/problems/letter-case-permutation/discuss/1068215/Detailed-c%2B%2B-solution-with-recursion-tree
class Solution {
private:
    bool isAlpha(string s , int i){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            return true;
        }
        return false;
    }
    
    void solve(string& S , int i , vector<string>&ans){
        if(i == S.size()) { // base condition
            ans.push_back(S);
            return;
        }
        
        if(isAlpha(S,i)) { // if the scanned character is alphabet
            
            S[i] = toupper(S[i]);
            
            solve(S,i+1,ans);
            
            S[i] = tolower(S[i]); 
            
            solve(S,i+1,ans);
        }
        else { // if the scanned character is number
             solve(S,i+1,ans);
        }
    
       
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int index = 0;
        
        solve(s , index , ans);
        return ans;
        
    }
};