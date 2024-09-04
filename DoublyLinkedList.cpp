#include<iostream>
using namespace std;


class Node {
    public:
        int data;
        Node* prev;
        Node* next;
        
        Node(int data){
            this -> data = data;
            this -> prev = NULL;
            this -> next = NULL;
        }
        
        ~Node(){
            int value = this -> data;
            if(next != NULL){
                delete next;
                next = NULL;
            }
            cout << "Node is deleted with data: " << value << endl;
        }
};


void insertAtHead(Node* &tail, Node* &head, int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }else{
         Node* temp = new Node(data);
         temp -> next = head;
         head -> prev = temp;
         head = temp;
    }
   
}

void insertAtTail(Node* &tail, Node* &head, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }else {
        Node* temp = new Node(data);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
    
}

void insertAtPosition(Node* &tail, Node* &head, int data, int position){
    Node* nodeToStart = new Node(data);
    Node* temp = head;
    int cnt = 1;
    if(position == 1){
        insertAtHead(tail, head, data);
        return;
    }
    
    if(temp -> next == NULL){
        insertAtTail(tail, head, data);
    }
    
    while(cnt < position - 1){
        temp = temp -> next;
        cnt++;
    }
      
    
    nodeToStart -> next = temp -> next;
    temp -> next -> prev = nodeToStart;
    temp -> next = nodeToStart;
    nodeToStart -> prev = temp;
}

int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void print(Node* &head){
    Node* temp = head;
    
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void deleteNode(Node* &tail, Node* &head, int position){
    if(position == 1){
        Node* temp  = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    
     Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr  -> next;
            cnt++;
        }
        
        if(curr -> next == NULL){
            tail = prev;
            prev -> next = NULL;
            curr -> prev = NULL;
            delete curr;
        }else if(curr -> next != NULL){
        prev -> next = curr -> next;
        curr -> prev = NULL;
        curr -> next = NULL;
        delete curr;
        }
}


int main(){
    Node* node1 = new Node(10);
    Node* head = node1; 
    Node* tail = node1;
    insertAtHead(tail, head, 20);
    insertAtHead(tail, head, 30);
    insertAtHead(tail, head, 40);
    print(head);
    insertAtTail(tail, head, 50);
    print(head);
    cout << "Lenght: " << getLength(head) << endl;
    insertAtPosition(tail, head, 60, 5);
      print(head);
      cout << "Tail: " << tail -> data << endl;
    deleteNode(tail, head, 6);
    cout << "Tail: " << tail  -> data <<endl;
    print(head);
    return 0;
}
