#include<iostream>
using namespace std;

class TwoStacks {
    int* arr;
    int size;
    int top1, top2;

public:
    // Constructor to initialize the size and top pointers
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;         // Stack 1 starts from the left
        top2 = n;          // Stack 2 starts from the right
    }

    // Method to push an element into Stack 1
    void push1(int x) {
        // Check if there is space between top1 and top2
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        } else {
            cout << "Stack Overflow for Stack 1\n";
        }
    }

    // Method to push an element into Stack 2
    void push2(int x) {
        // Check if there is space between top1 and top2
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        } else {
            cout << "Stack Overflow for Stack 2\n";
        }
    }

    // Method to pop an element from Stack 1
    int pop1() {
        if (top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        } else {
            return -1;  // Stack 1 is empty
        }
    }

    // Method to pop an element from Stack 2
    int pop2() {
        if (top2 < size) {
            int x = arr[top2];
            top2++;
            return x;
        } else {
            return -1;  // Stack 2 is empty
        }
    }
};

int main() {
    TwoStacks ts(5);  // Create a two-stack system with a total size of 5

    ts.push1(5);
    ts.push2(10);
    ts.push1(15);
    ts.push2(20);
    ts.push2(25);     // Trying to overflow

    cout << "Popped from Stack 1: " << ts.pop1() << endl;  // Should return 15
    cout << "Popped from Stack 2: " << ts.pop2() << endl;  // Should return 20

    return 0;
}

