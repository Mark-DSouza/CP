/*
    Given a linked list, write a fundciotn that divides it into two halves.
    This function shoudl modify the original list and then return a pointer to the 
    second half of the list.
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

Node *splitList(Node *head) {
    if (!head)
        return NULL;
    
    Node *runner(head -> next);

    while(runner) {
        runner = runner -> next;
        if (!runner) break;
        runner = runner -> next;
        head = head -> next;
    }

    Node *newHead = head -> next;
    head -> next = NULL;
    return newHead;
}

int main() {
    Node *head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);

    printList(head);
    cout << splitList(head) -> data << endl;
    return 0;
}

/*
    How to solve this question?
    This time we use a running pointer that is twice as much as the current pointer.
    So current starts at pos1..2..3 and runner starts at pos2..4..6
*/