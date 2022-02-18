// https://leetcode.com/problems/remove-k-digits/
Input: num = "1432219", k = 3
Output: "1219"
Input: num = "10200", k = 1
Output: "200"
class Solution {
    // TC = O(N)
    // SC = O(N)
public:
    string removeKdigits(string num, int k) {
        stack<char>stack;
        int len = num.length();
        // string ans = "";
        for(auto ch : num){
           
           while(!stack.empty() && stack.top() > ch && k >0){
                stack.pop();
                k--;
            }
            if(!stack.empty() || ch != '0'){
                stack.push(ch);
            }
            
        }
        // if k != 0 ; thats means your stack contain increase order of value {1,3,4,5,...n} , so remove ele from right side
        while(!stack.empty() && k--){
            stack.pop();
        }
         // edge case, 
        if(stack.empty()){
               return "0";
        }
        while(!stack.empty()){
            char temp = stack.top();
            // ans = temp+ans;
            num[len-1] = temp;
            len--;
            stack.pop();
        }
        return num.substr(len);
    }
};