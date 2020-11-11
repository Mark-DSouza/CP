/*
    Given a linked list where each node has two pointers,
    one to the next node and one to a random node in teh 
    list, write a funciton to clone the linked list.

    eg.

    1 -> 2 -> 3 -> 4 -> null
    v    v    v    v
    3    1    3    2
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x): data(x), next(NULL), random(NULL) {}
};

Node *clone(Node *head) {
    if (head == NULL)
        return NULL;

    Node *curr = head;
    while(curr) {
        Node *temp = new Node(curr -> data);
        temp -> next = curr -> next;
        curr -> next = temp;
        curr = temp -> next;
    }

    curr = head;
    while(curr) {
        curr -> next -> random = curr -> random -> next;
        curr = curr -> next -> next;
    }

    curr = head;
    Node *copy = head -> next;
    while(curr -> next) {
        Node *temp = curr -> next;
        curr -> next = curr -> next -> next; 
        curr = temp;
    }

    return copy;
}

void printList(Node *head) {
    while(head) {
        cout << head -> data << "[" << head -> random -> data << "]" << " ";
        head = head -> next;
    }
    
    cout << endl;
    return;
}

int main() {
    Node *head = NULL;
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node1 -> random = node3;
    node2 -> random = node1;
    node3 -> random = node3;
    node4 -> random = node2;
    printList(head);
    printList(clone(head));
    return 0;
}