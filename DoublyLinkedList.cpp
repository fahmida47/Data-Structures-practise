#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* root = NULL;
Node* tail = NULL;


// 1.Insert First
void InsertFirst(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->prev = NULL;
    temp->next = root;

    if (root != NULL) {
        root->prev = temp;
    } else {
        tail = temp; 
    }
    root = temp;
}

// 2.Insert Last
void InsertLast(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->next = NULL;
    temp->prev = tail;

    if (tail != NULL) {
        tail->next = temp;
    } else {
        root = temp; 
    }
    tail = temp;
}

// 3.Insert anywhere between 2 node[pos,value]
void InsertAfterPosition(int pos, int value) {
    Node* curr = root;
    int idx = 1;
    while (curr != NULL && idx < pos) {
        curr = curr->next;
        idx++;
    }
    if (curr == NULL) return;

    Node* temp = new Node();
    temp->data = value;
    temp->next = curr->next;
    temp->prev = curr;

    if (curr->next != NULL) {
        curr->next->prev = temp;
    } else {
        tail = temp;
    }
    curr->next = temp;
}

void InsertBeforePosition(int pos, int value) {
    if (pos == 1) {
        InsertFirst(value);
        return;
    }
    Node* curr = root;
    int idx = 1;
    while (curr != NULL && idx < pos) {
        curr = curr->next;
        idx++;
    }
    if (curr == NULL) return;

    Node* temp = new Node();
    temp->data = value;
    temp->next = curr;
    temp->prev = curr->prev;

    curr->prev->next = temp;
    curr->prev = temp;
}

void InsertAfterValue(int searchValue, int value) {
    Node* curr = root;
    while (curr != NULL && curr->data != searchValue) {
        curr = curr->next;
    }
    if (curr == NULL) return;

    Node* temp = new Node();
    temp->data = value;
    temp->next = curr->next;
    temp->prev = curr;

    if (curr->next != NULL) {
        curr->next->prev = temp;
    } else {
        tail = temp;
    }
    curr->next = temp;
}

void InsertBeforeValue(int searchValue, int value) {
    Node* curr = root;
    while (curr != NULL && curr->data != searchValue) {
        curr = curr->next;
    }
    if (curr == NULL) return;

    Node* temp = new Node();
    temp->data = value;
    temp->next = curr;
    temp->prev = curr->prev;

    if (curr->prev != NULL) {
        curr->prev->next = temp;
    } else {
        root = temp;
    }
    curr->prev = temp;
}

// 4.Delete First
void DeleteFirst() {
    if (root == NULL) return;
    Node* temp = root;
    root = root->next;
    if (root != NULL) root->prev = NULL;
    else tail = NULL;
    delete temp;
}

// 5.Delete Last
void DeleteLast() {
    if (tail == NULL) return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail != NULL) tail->next = NULL;
    else root = NULL;
    delete temp;
}

// 6.Delete anyehere between 2 node[pos,value]
void DeleteByPosition(int pos) {
    Node* curr = root;
    int idx = 1;
    while (curr != NULL && idx < pos) {
        curr = curr->next;
        idx++;
    }
    if (curr == NULL) return;

    if (curr->prev != NULL) curr->prev->next = curr->next;
    else root = curr->next;

    if (curr->next != NULL) curr->next->prev = curr->prev;
    else tail = curr->prev;

    delete curr;
}

void DeleteByValue(int value) {
    Node* curr = root;
    while (curr != NULL && curr->data != value) {
        curr = curr->next;
    }
    if (curr == NULL) return;

    if (curr->prev != NULL) curr->prev->next = curr->next;
    else root = curr->next;

    if (curr->next != NULL) curr->next->prev = curr->prev;
    else tail = curr->prev;

    delete curr;
}

// 7.Printing
void PrintingF() {
    Node* curr = root;
    cout << "Root: ";
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void PrintingB() {
    Node* curr = tail;
    cout << "Tail: ";
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

// 8.Searching
void Searching(int value) {
    Node* curr = root;
    int pos = 1;
    while (curr != NULL) {
        if (curr->data == value) {
            cout << value << " found at position " << pos << endl;
            return;
        }
        curr = curr->next;
        pos++;
    }
    cout << value << " not found!" << endl;
}

// 9.Last node
void LastNode() {
    if (tail != NULL)
        cout << "Last node: " << tail->data << endl;
}

// 10.Previous node
void PreviousOfLastNode() {
    if (tail != NULL && tail->prev != NULL)
        cout << "Previous of last node: " << tail->prev->data << endl;
}

// 11.Size
void ListSize() {
    Node* curr = root;
    int cnt = 0;
    while (curr != NULL) {
        cnt++;
        curr = curr->next;
    }
    cout << "Size of list: " << cnt << endl;
}


int main() {
    // INSERT
    InsertFirst(40);
    InsertFirst(30);
    InsertFirst(20);
    InsertFirst(10);
    InsertLast(50);
    InsertAfterPosition(1, 15);
    InsertBeforePosition(5, 35);
    InsertAfterValue(20, 26);
    InsertBeforeValue(10, 5);

    PrintingF();
    PrintingB();

    // DELETE
    DeleteFirst();
    DeleteLast();
    DeleteByPosition(3);
    DeleteByValue(26);

    PrintingF();
    PrintingB();

    // EXTRA
    Searching(35);
    Searching(100);
    LastNode();
    PreviousOfLastNode();
    ListSize();
    PrintingF();
    PrintingB();

    return 0;
}
