#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;

    Node (int k) : key(k), left(NULL), right(NULL) {}
};

void leftView(Node *root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int count = q.size();

        for (int i = 0; i < count; i++) {
            Node *curr = q.front();
            q.pop();

            if (i == 0) cout << curr -> key << " ";

            if (curr -> left != NULL) q.push(curr -> left);
            if (curr -> left != NULL) q.push(curr -> right);
        }
    }
}


int main() {
    Node* root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> right = new Node(50);

    leftView(root);
    return 0;
}