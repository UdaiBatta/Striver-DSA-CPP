#include<iostream>
using namespace std;

class Stack {
private:
    int top;        // Tracks the top of the stack
    int size;       // Size of the stack
    int* arr;       // Array to hold stack elements

public:
    // Constructor to initialize the stack
    Stack(int size) {
        this->size = size;
        arr = new int[size]; // Dynamically allocate memory for the stack
        top = -1;            // Initialize top to -1 (indicating the stack is empty)
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;   // Increment top and add value
    }

    // Function to remove the top element (pop)
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop" << endl;
            return;
        }
        top--;  // Simply decrement the top index to "remove" the top element
    }

    // Function to get the top element (peek)
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Return an invalid value when the stack is empty
        }
        return arr[top];  // Return the value at the top of the stack
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;  // If top is -1, the stack is empty
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == size - 1;  // If top is equal to size-1, the stack is full
    }

    // Function to print the stack elements
    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";  // Print elements from the bottom (index 0) to top
        }
        cout << endl;
    }
};

int main() {
    // Create a stack of size 5
    Stack s(5);

    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // Print the current stack
    s.printStack();  // Output: 10 20 30

    // Get the top element
    cout << "Top element: " << s.peek() << endl;  // Output: 30

    // Pop the top element
    s.pop();
    cout << "After popping, top element: " << s.peek() << endl;  // Output: 20

    // Print the stack again
    s.printStack();  // Output: 10 20

    // Push more elements
    s.push(40);
    s.push(50);
    s.push(60);  // Stack is now full
    s.printStack();  // Output: 10 20 40 50 60

    // Try pushing onto a full stack
    s.push(70);  // Output: Stack Overflow!

    return 0;
}

