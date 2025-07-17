/*
    Created by Abanoub on 7/17/2025.
*/

// Singly linked list is a non-linear data structure
/*
    Time complexity for operations:
    - insert at the beginning -> O(1)
    - insert at the end -> O(n)
    - insert at any position -> O(n)
    - delete first element -> O(1)
    - delete any other element -> O(n)
    - to know the size -> O(n)
*/

#include <iostream>
using namespace std;

// implementing
class Node {
    public:
    int data; // Current node data
    Node *next; // pointer to the next node

    // initialize a node with the value
    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};

class Linkedlist {
    public:
    Node *head;

    Linkedlist() {
        head = nullptr;
    }

    void insert_end(int x) {
        Node *newnode = new Node(x);
        if (head == nullptr) {
            head = newnode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void insert_begin(int x) {
        Node *newnode = new Node(x);
        newnode->next = head;
        head = newnode;
    }

    int size() {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr) {
            temp = temp->next;
            count++;
        }
        return count;
    }

    void insert_index(int index, int x) {
        // 0 indexing
        if (index < 0 or index > size()) {
            cout << "Invalid index" << endl;
            return;
        }
        if (index == 0) {
            insert_begin(x);
            return;
        }
        Node *temp = head;
        Node *newnode = new Node(x);
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void delete_begin() {
        if (head == nullptr) {
            cout << "Empty list" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void delete_index(int index) {
        if (index < 0 or index >= size()) {
            cout << "Invalid index" << endl;
            return;
        }
        if (index == 0) {
            delete_begin();
            return;
        }
        Node *temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node *newnode = temp->next;
        temp->next = newnode->next;
        delete newnode;
    }

    void delete_end() {
        if (head == nullptr) {
            cout << "Empty list" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

};