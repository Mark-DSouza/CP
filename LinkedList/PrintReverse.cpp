/*
    Given a linked list, write a function that prints the nodes of the list in reverse order.

    eg.
        printReversedList(1 -> 2 -> 3)
        3
        2
        1
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x): data(x), next(NULL) {}
};

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

void printReverse(Node *current) {
    if (current == NULL)
        return;

    printReverse(current -> next);

    cout << current -> data << endl;
}

int main() {
    Node *head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    printList(head);
    printReverse(head);
    return 0;
}