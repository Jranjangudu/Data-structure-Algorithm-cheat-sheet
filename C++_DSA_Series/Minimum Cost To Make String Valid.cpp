https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0
#include <stack>
int findMinimumCost(string str) {
  
    // if  length odd then it is a invalid return -1
    if(str.length() % 2 == 1){
        return -1;
    }
    stack<char>stack;
    // remove valid bracket
    for(int i = 0 ; i  < str.length() ; i++)  {
        char ch = str[i];
        if(ch == '{'){
           stack.push(ch);
        }
        else{
            if(!stack.empty() && stack.top() == '{'){
                stack.pop();
            }else{
                stack.push(ch);
            }
        }
    }
    int a = 0 , b =0;
    while(!stack.empty()){
        char top = stack.top();
        if(top == '{'){
            a++;
        }else{
            b++;
        }
        stack.pop();
    }
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}
Sample Input 1:
2
{{{}
{{}{}}
Sample Output 1:
1
0