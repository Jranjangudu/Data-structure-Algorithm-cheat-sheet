
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        // use Floyd Cycle Detection
        
        ListNode*slow = head , *fast=head; 
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next; 
            if(slow == fast)
                return true;
            
        }
        return false;
        // Time complexity O(n);
        // space complexity O(1)
        
        
        // Using map
//         if(head == NULL)
//             return false;
        
//         ListNode * temp = head;
//         map<ListNode* , bool> visited;
        
//         while(temp != NULL){
//             if(visited[temp] == true){
//                 return true;
//             }
//             visited[temp] = true;
//             temp = temp->next;
//         }
//         return false;
    }
};