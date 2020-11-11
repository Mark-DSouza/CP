#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;

    Node (int k) : key(k), left(NULL), right(NULL) {}
};

int isBalanced(Node *root) {
    if (root == NULL)
        return 0;

    int lh = isBalanced(root -> left);
    if (lh == -1) return -1;

    int rh = isBalanced(root -> right);
    if (rh == -1) return -1;

    if (abs(lh - rh) > 1) return -1;
    else return max(lh, rh) + 1;
}

int main() {
    Node *root = new Node(10);
    root -> left = new Node(5);
    root -> right = new Node(30);
    root -> right -> left = new Node(15);

    cout << isBalanced(root) << endl;
}