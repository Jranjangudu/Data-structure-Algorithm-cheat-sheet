https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644?leftPanelTab=0

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,5,4]

Node* kReverse(Node* head, int k) {

     // base case
        if(head == NULL){
            return NULL;
        }
        
        Node * prev = NULL;
        Node * curr = head;
        Node * nextNode = NULL;
        int count = 0;
        // step1: reverse the k size of Node
        while(curr != NULL && count < k){
            nextNode = curr->next;
            curr->next = prev;
            prev =curr;
            curr = nextNode;
            count++;
        }
        // step2: Recursive call the next part of lists
        if(nextNode != NULL){
            head->next = kReverse(nextNode , k);
        }
        // step3: return prev;
        return prev;
}