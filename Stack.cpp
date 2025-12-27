#include <bits/stdc++.h>
using namespace std;

// ==================== Array-Based Stack ====================
namespace ArrayStack {
    int top = -1;
    int MaxStk;
    int* stackArr;

    void push(int value) {
        if (top == MaxStk - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            top++;
            stackArr[top] = value;
            cout << value << " pushed into array stack." << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Nothing to pop." << endl;
        } else {
            cout << stackArr[top] << " popped from array stack." << endl;
            top--;
        }
    }
    void display() {
        if (top == -1) {
            cout << "Array stack is empty." << endl;
        } else {
            cout << "Array stack elements: ";
            for (int i = top; i >= 0; i--)
                cout << stackArr[i] << " ";
            cout << endl;
        }
    }

    void cleanup() {
        delete[] stackArr;
    }
}

// ==================== Linked List Stack ====================
namespace LinkedStack {
    struct Node {
        int data;
        Node* next;
    };

    Node* top = NULL;

    void push(int value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = top;
        top = temp;
        cout << value << " pushed into linked stack." << endl;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow! Nothing to pop." << endl;
        } else {
            Node* curr = top;
            cout << top->data << " popped from linked stack." << endl;
            top = top->next;
            delete curr;
        }
    }

    void display() {
        if (top == NULL) {
            cout << "Linked stack is empty." << endl;
            return;
        }
        cout << "Linked stack elements: ";
        Node* curr = top;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void cleanup() {
        while (top != NULL) pop();
    }
}

// ==================== Main Function ====================
/*int main() {
    using namespace ArrayStack;

    cout << "Enter array stack size: ";
    cin >> MaxStk;
    stackArr = new int[MaxStk];

    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    pop();
    pop();
    pop(); // extra pop to show underflow

    cleanup(); // free array memory*/
int main() {
    // Array stack
    cout << "Enter array stack size: ";
    cin >> ArrayStack::MaxStk;
    ArrayStack::stackArr = new int[ArrayStack::MaxStk];

    ArrayStack::push(10);
    ArrayStack::push(20);
    ArrayStack::push(30);
    ArrayStack::display();

    ArrayStack::pop();
    ArrayStack::display();

    ArrayStack::pop();
    ArrayStack::pop();
    ArrayStack::pop(); // extra pop to show underflow

    ArrayStack::cleanup(); // free array memory

    cout << "\n--- Linked List Stack ---\n";

    // Linked list stack
    LinkedStack::push(100);
    LinkedStack::push(200);
    LinkedStack::push(300);
    LinkedStack::display();

    LinkedStack::pop();
    LinkedStack::display();

    LinkedStack::pop();
    LinkedStack::pop();
    LinkedStack::pop(); // extra pop to show underflow

    LinkedStack::cleanup(); // free linked list memory

    return 0;
}
