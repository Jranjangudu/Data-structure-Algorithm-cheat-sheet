https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1/#

Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4

Input:
N = 5
value[] = {2,2,2,2,2}
Output: 2

Time complexity = O(n)
space complexity = O(n) // because of using map

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     map<int , bool>visited;
        Node * cur = head;
        Node * dummy = new Node(-1);
        Node * temp = dummy;
        while(cur != NULL){
            if(visited[cur->data] == true){
                Node * delete_node = cur;
                cur = cur->next;
                // memory free
                delete(delete_node);
            }
            else{
                visited[cur->data] = true;
                dummy->next = cur;
                dummy = cur;
                cur = cur->next;
            }
        }
        dummy->next = NULL;
        return temp->next;
    }
};

