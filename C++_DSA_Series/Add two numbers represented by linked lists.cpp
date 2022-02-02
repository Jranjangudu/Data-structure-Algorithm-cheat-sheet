https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#
Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
// Total Time Complexity = O(m) + O(n) + O(max(m,n) + O(m+n) == O(M + N)
// Space complexity = O(Max(N,M))
// Time complexity = O(M + N)
class Solution
{
    private:
        Node* reverseNode(Node* head){
            Node * prev = NULL;
            while(head != NULL){
                Node * nextptr = head->next;
                head ->next = prev;
                prev = head;
                head = nextptr;
            }
            return prev;
        }
        void insertAtTail(Node* &head , Node* &tail , int val){
            Node * temp = new Node(val);
            if(head == NULL){
                head = temp;
                tail = temp; 
                return;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
        }
        
        Node * addLists(struct Node* first, struct Node* second){
            int carry = 0;
            Node * head = NULL;
            Node * tail = NULL;
            while(first != NULL || second != NULL || carry != NULL){
        
                int val1 = 0;
                if(first != NULL){
                    val1 = first->data;
                }
                
                int val2 = 0;
                if(second != NULL){
                    val2 = second->data;
                }
                
                int sum = carry + val1 + val2;
                int digit = sum % 10;
               // create new node and add in answer linkedlist
                insertAtTail(head , tail , digit); // space taken O(max(M , N))
                
                carry = sum / 10;
                
                if(first != NULL)
                    first = first->next;
                if(second != NULL)
                    second = second->next;
            }
            return head;
        }
        
    public:
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // reverse first LL
        first = reverseNode(first); // TC-> O(m)
        // reverse second LL
        second = reverseNode(second); // TC --> O(n)
        
        // add two LL
        Node * ans = addLists(first , second); // TC --> O(max(m,n))
        // reverse ans LL
        ans = reverseNode(ans);// TC --> O(m+n)
        return ans;
        
    }
};