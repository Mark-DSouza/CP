/*
    Given a linked list, write a function to determine whertehr the list is a palindrome.
    
    eg.
    palindrome(1 2 3) = false
    palindrome(1 2 1) = true
*/

#include <iostream>
#include <stack>
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

bool palindrome(Node *head) {
    Node *current(head), *runner(head);
    stack<int> s;

    while(runner != NULL && runner -> next != NULL) {   // !(Even pal condition) && !(Odd pal condition)
        s.push(current -> data);
        current = current -> next;
        runner = runner -> next -> next;
    }

    if (runner != NULL)
        current = current -> next;

    while (current) {
        if (current -> data != s.top())
            return false;
        s.pop();
        current = current -> next;
    }

    return true;
}

int main() {
    Node *head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    // head = insertEnd(head, 3);
    head = insertEnd(head, 2);
    head = insertEnd(head, 1);
    printList(head);
    cout << palindrome(head) << endl;
    return 0;
}

/* 
    How to solve this problem?
    You basically store the first half of the list in a FIFO data structure and compare it
    with the second half

    Check for even and odd cases
    current and runner init to head

    For an odd palindrome runner is at the last node and current is at the middle node
        So no need to perform comparison for the middle element
    
    For an even palindrome, runner is at NULL and current is at first node of second half
        So all comparisons need to begin from current's position
*/