
// https://leetcode.com/problems/reverse-nodes-in-k-group/

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1){
            return head;
        }
        
        ListNode * dummy = new ListNode();
        dummy->next = head;
        
        ListNode * cur = dummy , *nextNode = dummy , *prev = dummy;
        
        int count = 0;
        // count the node
        while(cur->next != NULL){
            count++;
            cur = cur -> next;
        }
        
        while(count >= k){
            cur = prev -> next;
            nextNode = cur -> next;
            
            for(int i =1 ; i < k ; i++){
                cur -> next = nextNode -> next;
                nextNode -> next = prev -> next;
                prev -> next = nextNode;
                nextNode = cur -> next;
            }
            prev = cur;
            count -= k;
            
        }
        return dummy->next;
     
    }
};


