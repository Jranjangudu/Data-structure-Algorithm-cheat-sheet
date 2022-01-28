https://leetcode.com/problems/linked-list-cycle-ii/

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Floyd Cycle Detection
        
        ListNode*slow = head , *fast=head; 
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next; 
            if(slow == fast){
                // Another logic , point slow to head and move fast and slow 1 step at-a-time;
                slow = head;
                while(slow != fast){
                    slow = slow->next; 
                    fast = fast->next;
                    
                }
                return slow;
            }
                
            
        }
        return NULL;
    }
};
// time complexity O(n)
// space complexity O(1)