https://leetcode.com/problems/copy-list-with-random-pointer/
// approach 1 , without using map
class Solution {
     // TC = O(N);
    // SC = O(1)
private:
    void insertAtTail(Node * &head , Node * &tail , int val){
        Node * newNode = new Node(val);
        if(head == NULL){
                head = newNode;
                tail = newNode;
         }else{
                tail->next = newNode;
                tail = tail->next;
        }
    }
public:
    Node* copyRandomList(Node* head){
         //step 1 = create a clone node
        Node * cloneHead = NULL;
        Node * cloneTail = NULL;
        
        Node * temp = head;
       
        while(temp != NULL){
            insertAtTail(cloneHead ,cloneTail , temp->val);
            temp = temp -> next;
        }
        // step 2 = clone node add in between original none
        Node * originalNode = head;
        Node * cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            
            Node* orgnext = originalNode->next;
            originalNode->next = cloneNode;
            
            Node* clonnext = cloneNode->next;
            cloneNode->next = orgnext;
            
            originalNode = orgnext;
            cloneNode =clonnext;
            
        }
        
        // step 3 = random pointer copy
        temp = head;
        while(temp != NULL){
            if(temp->next != NULL){
                temp->next->random = temp->random != NULL ? temp->random->next : NULL;
            }
            temp = temp->next->next;
        }
        // step 4 = come back to original clone node changes done by step 2
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            originalNode -> next = cloneNode->next;
            originalNode =  originalNode -> next;
            if(originalNode != NULL){
                cloneNode -> next = originalNode->next;
            }
            cloneNode =  cloneNode -> next;
        }
        // return clonenode
        return cloneHead;
    }
};
-------------------------------------------------------------------------------
// approach 2 , usign map
class Solution {
    // TC = O(N);
    // SC = O(N)
private:
    void insertAtTail(Node * &head , Node * &tail , int val){
        Node * newNode = new Node(val);
        if(head == NULL){
                head = newNode;
                tail = newNode;
         }else{
                tail->next = newNode;
                tail = tail->next;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        // step 1 , create a clone LL
        Node * cloneHead = NULL;
        Node * cloneTail = NULL;
        
        Node * temp = head;
       
        while(temp != NULL){
            insertAtTail(cloneHead ,cloneTail , temp->val);
            temp = temp -> next;
        }
        // step-2 create a map
        unordered_map<Node* , Node*> mapping;
        
        Node * originalNode = head;
        Node * cloneNode = cloneHead;
        
        while(originalNode != NULL){
            mapping[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        // step 3 random point set by the help of map
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL){
            cloneNode -> random = mapping[originalNode->random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        return cloneHead;
    }
};