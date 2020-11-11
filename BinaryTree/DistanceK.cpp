/*
    Print the nodes that are at a distance of k from the root.
    In other words, print the (k + 1)th level.
 */

#include <iostream>
using namespace std;


struct Node {
    int key;
    Node *left;
    Node *right;

    Node (int k) : key(k), left(NULL), right(NULL) {}
};

void distanceK(Node *root, int k) {
    if (root == NULL)
        return;

    if (k == 0)
        cout << root -> key << " ";

    else {
        distanceK(root -> left, k - 1);
        distanceK(root -> right, k - 1);
    }
}

int main() {
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> left -> left = new Node(40);
    root -> left -> right = new Node(50);
    root -> right -> right = new Node(70);
    root -> right -> right -> right = new Node(80);

    distanceK(root, 2);
    return 0;
}