https://leetcode.com/problems/partition-list/
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode * before_head = new ListNode(-1);
        ListNode * before = before_head;
      
        ListNode * after_head = new ListNode(-1);
        ListNode * after = after_head;
        
        while(head != NULL){
             // If the original list node is lesser than the given x,
            // assign it to the before list.
            if(head->val < x){
                before -> next = head;
                before = before->next;
            }
            else{
                // If the original list node is greater or equal to the given x,
                // assign it to the after list.
                after ->next = head;
                after = after->next;
            }
             // move ahead in the original list
            head = head ->next;
        }
         // Last node of "after" list would also be ending node of the reformed list
        after->next  = NULL;
        
        // marge two node
        // Once all the nodes are correctly assigned to the two lists,
        // combine them to form a single list which would be returned.
        before->next = after_head->next;
        return before_head->next;
      
    }
};