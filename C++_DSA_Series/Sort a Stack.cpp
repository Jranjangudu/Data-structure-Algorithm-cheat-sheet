// TC = O(n^2)
void sortedInsert(stack<int> &stack , int val){
    // base case
    if(stack.empty() || (!stack.empty() && stack.top() < val)){
        stack.push(val);
        return;
    }
    int n = stack.top();
    stack.pop();
    sortedInsert(stack , val);
    stack.push(n);
}
void sortStack(stack<int> &stack)
{
	// base case
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    
    // RECURSIVE CALL
    sortStack(stack);
    sortedInsert(stack , num);
}