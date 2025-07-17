/*
    Created by Abanoub on 7/17/2025.
*/

// Stack is a LIFO data structure last in first out
// Time complexity for all operations is O(1)

// implementing using vector
#include "iostream"
#include "vector"
using namespace std;
class vector_stack {
private:
    // our array
    vector<int> arr;
public:
    // constructor to initialize new Stack
    vector_stack() {};

    // push method to add new element
    void push(int x) {
        arr.push_back(x);
    }

    // top method to return the top value
    int top() {
        if (arr.size() != 0) return arr.back();
        return -1;
    }

    // pop method to erase the top element
    void pop() {
        if (arr.size() != 0) arr.pop_back();
    }

    // method to check if the stack is empty
    bool isempty() {
        return arr.size() == 0;
    }
};

class array_stack {
private:
    int arr[100];
    int Top = -1;
    public:
    array_stack() {};
    void push(int x) {
        if (Top < 99) arr[++Top] = x;
        else cout<<"Stack Overflow"<<endl;
    }
    void pop() {
        if (Top == -1) cout<<"Stack Underflow"<<endl;
        else Top--;
    }
    bool isempty() {
        return Top == -1;
    }
    int top() {
        if (Top != -1) return arr[Top];
        return -1;
    }
};

int main() {

    vector_stack stack;
    stack.push(10);
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.isempty() << endl;
    return 0;
}