/*
    Print the first node from the left at each level
*/

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;

    Node (int k) : key(k), left(NULL), right(NULL) {}
};

int maxLevel = 0;

void leftView(Node *root, int level) {
    if (root == NULL)
        return;

    if (maxLevel < level) {
        cout << root -> key << " ";
        maxLevel = level;
    }

    if (root -> left != NULL) leftView(root -> left, level + 1);
    if (root -> right != NULL) leftView(root -> right, level + 1);
}

int main() {
    Node* root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> right = new Node(50);

    leftView(root, 1);
    return 0;
}

/*
    We're doing a preorder on the tree and also using the variable maxLevel to check whether it 
    is the first node at a particular level
*/