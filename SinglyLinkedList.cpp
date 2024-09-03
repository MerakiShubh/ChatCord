#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    
    ~Node(){
        cout << "Value: " << this -> data << endl;
        
        if(this -> next != NULL){
            // delete next;
            this -> next = NULL;
        }
        
        cout << "Node is delete for value: " << this -> data << endl;
    }
};

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int data) {
    if (position == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // Traverse to the position just before the target position
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    // If inserting at the last position (i.e., after the last node)
    if (temp != NULL && temp->next == NULL) {
        insertAtTail(tail, data);
        return;
    }

    // Normal insertion in the middle of the list
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Traversing the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void deleteNode(Node* &tail, Node* &head, int position){
    Node* temp = head;
    
    //delete node at first position
    if(position == 1){
          head = head -> next;
          temp -> next = NULL;
          delete temp;
    }
    
    
    //traversing to the intended postion
    
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;
    while(cnt < position){
        prev = curr;
        curr = curr -> next;
        cnt++;
    }
    
    //deleting last node and handling tail in that case 
    if(curr != NULL && curr -> next == NULL){
        tail = prev;
        prev -> next = NULL;
        delete curr;
    }
    
    // deleting in between node in a linked list
    else if(curr != NULL){
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main() {
    Node* node1 = new Node(10);
    Node* tail = node1;
    Node* head = node1;

    print(head);

    insertAtTail(tail, 20);
    print(head);

    insertAtHead(head, 20);
    print(head);

    insertAtTail(tail, 30);
    print(head);

    insertAtHead(head, 30);
    print(head);

    insertAtPosition(tail, head, 4, 50);
    print(head);
    
    cout << "Tail: " << tail -> data << endl;
    
    deleteNode(tail, head,6);
    
     cout << "Tail: " << tail -> data << endl;
    
    print(head);

    return 0;
}
