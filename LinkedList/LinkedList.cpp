#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;    
    }
};

Node *insertBegin(Node *head, int x) {
    Node *temp = new Node(x);
    temp -> next = head;
    return temp;
}

Node *insertEnd(Node *head, int x) {
    Node *temp = new Node(x);
    
    if (!head)
        return temp;
    
    Node *current = head;
    while(current -> next)
        current = current -> next;
    current -> next = temp;
    return head;
}

void printList(Node *head) {
    while(head) {
        cout << head -> data << " ";
        head = head -> next;
    }
    
    cout << endl;
    return;
}

int main() {
    // Node *head = new Node(10);
    // head -> next = new Node(20);
    // head -> next -> next = new Node(30);
    
    // Node *head = NULL;
    // head = insertBegin(head, 10);
    // head = insertBegin(head, 20);
    // head = insertBegin(head, 30);

    Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    printList(head);
    return 0;
}