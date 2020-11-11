/*
    Design a stack with a push, pop, and max funciton
    which returns the max value in the stack, all of which are run in O(1) time

    stack = 1 -> 2 -> 3 -> 2 -> 1
    max = 3
*/
#include <iostream>
#include <exception>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *oldMax;

    Node(int x): data(x), next(NULL), oldMax(NULL) {}
};

class Stack {
    Node *top;
    Node *mx;

    public:
        Stack(): top(NULL), mx(NULL) {}
        int max();
        void push(int data);
        int pop();
        void printStack();
};

void Stack::push(int data) {
    Node *temp = new Node(data);
    temp -> next = top;

    if (mx == NULL || data > mx -> data) {
        temp -> oldMax = mx;
        mx = temp;
    }

    top = temp;
    return;
}

int Stack::pop() {
    try
    {
        if (!top)
            throw std::underflow_error("Stack is empty");

        if (top -> oldMax)
            mx = top -> oldMax;

        if (!top -> next)
            mx = NULL;
        
        Node *temp = top;
        top = top -> next;

        // Cleanup and return
        int x = temp -> data;
        delete temp;
        return x;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int Stack::max() {
    if (!mx)
        return -1;
    return mx -> data;
}

void Stack::printStack() {
    Node *current = top;
    cout << "Stack:  ";
    while(current) {
        cout << current -> data << "[" <<(current -> oldMax ? current -> oldMax -> data : -1) << "]" << "  ";
        current = current -> next;
    }
    cout << endl;
    return;
}

int main() {
    // Stack s;
    // s.push(1);
    // s.printStack();
    // cout << "Max:  "  << s.max() << endl;
    // s.push(2);
    // s.printStack();
    // cout << "Max:  "  << s.max() << endl;
    // s.push(1);
    // s.printStack();
    // cout << "Max:  "  << s.max() << endl;
    // s.pop();
    // s.printStack();
    // cout << "Max:  " << s.max() << endl;
    // s.pop();
    // s.printStack();
    // cout << "Max:  " << s.max() << endl;

    Stack s;
    s.push(1);
    s.printStack();
    s.pop();
    s.printStack();
    cout << "Max:  " << s.max() << endl;
    s.pop();
    s.printStack();
    cout << "Max:  " << s.max() << endl;
    return 0;
}

/*
    How to solve this problem in O(1) time?
    Store a pointer to the previous maximum every time a new maximum node is added.
    If it does get popped, you always have the old maximum to remember.
    stack = 1 -> 2 -> 3 -> 2 -> 1
            v    v    v    v    v
            N    N    2    1    N        <-- Pointers to previous maximums
*/