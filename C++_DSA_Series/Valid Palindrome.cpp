// https://leetcode.com/problems/valid-palindrome/
class Solution {
private:
    bool validChar(char ch){
        if((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z')||(ch >= '0' && ch <= '9')){
            return 1;
        }
        return 0;
    }
    
    char toLowerCase(char ch){
        if((ch >= 'a' && ch <='z') || (ch >= '0' && ch <= '9')){
            return ch;
        }
        else{
            char temp = ch - 'A' +'a';
            return temp;
        }
    }
    
    bool checkPalindrome(string st){
        int start = 0;
        int end = st.length()-1;
        while(start <= end){
            if(st[start] != st[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        string str = "";
        // remove non-alphanumeric characters
        for(int i = 0 ; i < s.size() ; i++){
            if(validChar(s[i])){
                str.push_back(s[i]);
            }
        }
        
        // convert all char to lowercase;
        for(int i =0 ; i < str.length() ; i++){
            str[i] = toLowerCase(str[i]);
        }
        // check palindrome or not;
        
        return checkPalindrome(str);
    }
};