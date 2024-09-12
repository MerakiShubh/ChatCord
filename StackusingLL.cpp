// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Stack{
    public:
    int data;
    Stack* next;
    
    Stack(int data){
        this -> data = data;
        this -> next = NULL;
    }
};


Stack* push(int data, Stack* head){
    Stack* newNode = new Stack(data);
    newNode->next = head;
    head = newNode;
    return head;
}

int pop(Stack* &head){
    if(head == NULL){
        cout << "Stack is underflow" << endl;
        return -1;
    }
    
    int data = head -> data;
    Stack* temp = head;
    head = head -> next;
    delete temp;
    return data;
}

int peek(Stack* head){
    if(head == NULL){
        cout << "Stack is empty" << endl;
        return -1;
    }
    
    return head -> data;
}




int main() {
    
    Stack* head = nullptr;
    head = push(10, head); // Assign the returned value to head
    head = push(20, head); // Same here
    head = push(30, head); 
    head = push(40, head); 
    
    // Fix the typo in 'cout'
    
    
    cout << "Pop element: " << pop(head) << endl;
    cout << "Pop element: " << pop(head) << endl;
    cout << "Pop element: " << pop(head) << endl;
    
    cout << "Peek of stack: " << peek(head) << endl;
    return 0;
}
