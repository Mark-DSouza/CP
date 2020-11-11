#include <iostream>
#include <unordered_set>
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

void dedup(Node *head) {
    unordered_set<int> nodes;
    Node *curr(head), *prev(NULL);
    while(curr) {
        if (nodes.find(curr -> data) != nodes.end()) {
            prev -> next  = curr -> next;
            delete curr;
        }
        else {
            nodes.insert(curr -> data);
            prev = curr;
        }
        curr = prev -> next;
    }
}




int main() {
    Node *head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 2);
    head = insertEnd(head, 1);

    printList(head);
    dedup(head);
    printList(head);
    return 0;




}