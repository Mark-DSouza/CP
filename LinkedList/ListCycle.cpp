/*
    Given a linked list, determine whether or not it contains a cycle

    eg.
    1 -> 2 -> 3 -> 4         true
         ^         |
         |_________|

    1 -> 2 -> 3 -> 4 -> 3 -> 4 -> null          true
*/

#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x): data(x), next(NULL) {}
};

// Node *insertEnd(Node *head, int x) {
//     Node *temp = new Node(x);
    
//     if (!head)
//         return temp;
    
//     Node *current = head;
//     while(current -> next)
//         current = current -> next;
//     current -> next = temp;
//     return head;
// }

// void printList(Node *head) {
//     while(head) {
//         cout << head -> data << " ";
//         head = head -> next;
//     }
    
//     cout << endl;
//     return;
// }

// bool hasCycle(Node *head) {
//     unordered_set<Node*> s;

//     while(head) {
//         if (s.find(head) != s.end())
//             return true;

//         s.insert(head);
//         head = head -> next;
//     }
//     return false;
// }

bool hasCycle(Node *head) {
    if (head == NULL)
        return false;

    Node *curr(head);
    Node *runner(head -> next);
    while(runner != NULL && runner -> next != NULL) {
        if (runner == curr)
            return true;
        curr = curr -> next;
        runner = runner -> next -> next;
    }
    return false;
}

int main() {
    Node *head = NULL;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    // node4 -> next = node2

    // printList(head);
    cout << hasCycle(head) << endl;

    return 0;
}