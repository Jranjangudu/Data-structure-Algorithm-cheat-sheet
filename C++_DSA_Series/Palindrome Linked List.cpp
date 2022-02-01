https://leetcode.com/problems/palindrome-linked-list/
Input: head = [1,2,2,1]
Output: true
Input: head = [1,2]
Output: false

// Time complexity O(n)
// // Space complexity O(1) 
class Solution {
private:
     ListNode* middle_Node(ListNode*head){
         ListNode * slow = head;
         ListNode* fast = head;
         
         while(fast != NULL && fast->next != NULL){
             slow = slow->next;
             fast = fast->next->next;
         }
         return slow;
     };
    ListNode* reverse_Node(ListNode*mid){
        ListNode * prev = NULL;
        while(mid != NULL){
            ListNode * nextptr = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextptr;
        }
        return prev;
    }
    bool checkPalindrome(ListNode* head , ListNode*reverse){
        while(head != NULL && reverse != NULL){
            if(head->val != reverse->val){
                return false || 0;
            }
            head = head->next;
            reverse = reverse->next;
        }
        return true || 1;
    }
public:
    bool isPalindrome(ListNode* head) {
        // find the middle
        ListNode* mid = middle_Node(head);
        // reverse the list after middle
        ListNode* reverse = reverse_Node(mid);
        // compare both modified head and reverse list
        return checkPalindrome(head , reverse);
       
    }
};