// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

class Solution {
private:
   void solve(string digits ,int index ,string output ,vector<string> &ans , string mapping[]){
        
        // base case 
        if(index >= digits.length()){
            ans.push_back(output); 
            return;
        }
        // get the number
        int number = digits[index] - '0'; // - '0' , because digits[index] return a char value , but i need integer value
       
       // map corresponding value
        string value = mapping[number];
        // running a loop for  each char  
        for(int i = 0 ; i < value.length() ; i++){
            output.push_back(value[i]);
            // recursive call
            solve(digits , index+1 ,  output , ans, mapping);
            // backtracking
            output.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        // Edge cases
        if(digits.length() == 0){
            return ans;
        }
        string output ="";
        int index = 0;
        string mapping[10] ={"" ,"" , "abc" , "def" , "ghi" , "jkl" , "mno" ,"pqrs" ,"tuv" ,"wxyz"};
        
        solve(digits , index ,  output , ans, mapping );
        return ans;
        
    }
};