class Solution {
    // TC = O(n)
    // Sc = O(n)
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i =0  ; i < s.length() ; i++){
            // if opening bracket stack push 
            char ch =s[i];
            if(ch == '[' || ch == '{' || ch == '('){
                st.push(ch);
            }else{
                // if closing bracket then stacktop and check and pop
                if(!st.empty()){
                    char top = st.top();
                    if((ch == '}' && top == '{') ||
                       (ch == ')' && top == '(') ||
                       (ch == ']' && top == '[')){
                        st.pop();
                    }else{
                       return false;
                    }
                }else return false;
            }
        }
        if(st.empty()){
            return true;
        }return false;
    }
};