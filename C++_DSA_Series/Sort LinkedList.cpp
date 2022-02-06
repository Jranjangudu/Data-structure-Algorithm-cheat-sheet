class Solution {
    // TC = O(OlogN)
    // sc = O(logN)
private:
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeTwoList(ListNode* left , ListNode* right){
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        
        while(left != NULL && right != NULL){
            if(left->val < right->val){
                temp->next = left;
                temp = left;
                left = left->next;
            }else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        
        if(left != NULL){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        if(right != NULL){
            temp->next = right;
            temp = right;
            right = right->next;
        }
        
        ans = ans->next;
        return ans;
    }
public:
    ListNode* sortList(ListNode* head) {
        // base case 
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        // find mid node of LL
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        
        // recursive call
        left = sortList(left);
        right = sortList(right);
        
        // merge two LL
        ListNode* result = mergeTwoList(left , right);
        return result;
        
    }
};