/*
    Given a singly linked list, write a function to find the nth-to-last element of the list

    Eg.
        list = 1 -> 2 -> 3 -> 4 -> 5

        n = 1, output = 4
        n = 2, output = 3
        n = 3, output = 2
        etc.
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

    Node *current(head);
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

Node* nthToLast(Node *head, int n) {
    Node *current(head), *follow(head);

    for (int i = 1; i <= n; i++)
    {
        if (!current -> next)
            return NULL;
        current = current -> next;
    }

    while(current -> next) {
        current = current -> next;
        follow = follow -> next;
    }

    return follow;
}

int printNode(Node *node) {
    if (node)
        return node -> data;
    return -1;
}

int main() {
    Node *head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);

    cout << printNode(nthToLast(head, 0)) << endl;
    cout << printNode(nthToLast(head, 1)) << endl;
    cout << printNode(nthToLast(head, 4)) << endl;
    cout << printNode(nthToLast(head, 5)) << endl;

    return 0;
}


/*
    How to solve this problem?
    Easy. We create a follower pointer to the current pointer that is exactly n elements behind

    list = 1 -> 2 -> 3 -> 4 -> 5; n = 2

    list = 1 -> 2 -> 3 -> 4 -> 5
    current^
    follow ^

    list = 1 -> 2 -> 3 -> 4 -> 5
    current                    ^
    follow           ^
*/