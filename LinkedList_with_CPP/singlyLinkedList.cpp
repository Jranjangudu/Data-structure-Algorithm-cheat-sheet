#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node*next;
    //constructor
    Node(int data){
      this->data = data;
      this->next = NULL;
    }

    // destructor
    ~Node(){
      int value = this->data;
      // memory free
      if(this->next != NULL){
        delete next;
        this->next = NULL;

      }
      cout << "memory is free for node with data : " << value << endl;
    }
};

class singlyLinkedList{
  public:
  // create a head
  Node *head = NULL;
  Node *tail = NULL;

  // insert node
  void insertNode(int data){
    // create a new node
    Node * newNode = new Node(data);
    if(head == NULL){
      head = newNode;
      tail = newNode;
    }else{
      newNode->next = head;
      head = newNode;
    }
  }
  
  // insert data in tail position
  void insertInTail(int data){
    // create a new node
    Node * newNode = new Node(data);
     if(tail == NULL){
      tail = newNode;
      head = newNode;
    }else{
      tail->next = newNode;
      tail = newNode;
    }
  }


  void insertAtPosition(int position , int val){
    if(position == 1){
      insertNode(val);
      return;
    }
    int cnt = 1;
    Node * temp = head;
    while(cnt < position-1){
      temp = temp -> next;
      cnt++;
    }

      // handle tail edge case
    if(temp->next == NULL){
      insertInTail(val);
      return;
    }

    // create insert node
    Node * insertNode = new Node(val);
    insertNode->next = temp->next;
    temp->next = insertNode;
  
  }

  // Delete node by the help of position

  void deleteNode(int position){
    if(position == 1){
      Node * temp = head;
      head = head->next;

      // memory free start node
      temp->next = NULL;
      delete temp;
      return;
    }

    Node * cur  = head;
    Node * prev  = NULL;
    int cnt = 1; 
    while(cnt < position){
      prev = cur;
      cur = cur->next;
      cnt++;
    }
    prev->next = cur->next;
   // handle tail edge case
    if(cur->next == NULL){
      tail = prev;
    }

    cur->next = NULL;
    // memory free
    delete cur;
  }

  // traverse linkedlist
  void traverse(){
    Node * temp = head;
    while(temp){
      cout << temp->data << " --> " ;
      temp = temp->next;
    }
  }

};

int main() {

  singlyLinkedList * s1 = new singlyLinkedList;
  s1->insertNode(10);
  s1->insertNode(20);

  // insertInTail
  s1->insertInTail(103);
  s1->insertInTail(104);
  
  // insertAtPosition
  s1->insertAtPosition(1, 99);
  s1->insertAtPosition(6, 88);

/*
  s1->traverse();
  cout << endl;
  */
  // Delete node
  s1->deleteNode(5);
  s1->deleteNode(2);

  s1->traverse();

  return 0;
} 