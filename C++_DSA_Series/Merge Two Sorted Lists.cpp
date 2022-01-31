https://leetcode.com/problems/merge-two-sorted-lists/
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

class Solution {
private:
     ListNode* solve(ListNode* list1, ListNode* list2){
         
   // if list1 list have only one node , point its next to entire list2 list
    if(list1->next == NULL){
        list1->next = list2;
        return list1;
    }
         
   ListNode* curr1 = list1;
   ListNode* next1 = curr1->next;
   ListNode* curr2 = list2;
   ListNode* next2 = curr2->next;
    
    while(next1 != NULL && curr2 != NULL){
        if((curr1->val <= curr2->val)
          	&& next1->val >= curr2->val){
            // add node in between the node of list1 list 
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            // update pointer
            curr1 = curr2;
            curr2 = next2;
        }else{
            // go one step ahead in list1 list
             curr1 =next1;
             next1 = next1->next;

            if(next1 == NULL){
                curr1->next = curr2;
                return list1;
            }
        }
       
    }
     return list1;
}
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
    if(list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list1;
    }
    // Write your code here.
    if(list1->val <= list2->val){
        return solve(list1 , list2);
    }else{
        return solve(list2 , list1);
    }
        
    }
}; // Time complexity O(n)
// space complexity O(1)