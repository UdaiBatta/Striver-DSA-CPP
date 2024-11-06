#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* previous;

    Node() {
        this->data = 0;
        next = NULL;
        previous = NULL;
    }

    Node(int data) {
        this->data = data;
        this->previous = NULL;
        this->next = NULL;
    }

    Node(int data, Node* previous, Node* next) {
        this->data = data;
        this->previous = previous;
        this->next = next;
    }
};

// Function to convert array to doubly linked list
Node* convertArr2DLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* previous = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        temp->previous = previous;
        previous->next = temp;
        previous = temp;
    }
    return head;
}

// Function to reverse a doubly linked list
Node* reverseDLL(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; // No need to reverse if list is empty or has one node
    }

    Node* current = head;
    Node* previous = NULL;

    while (current != NULL) {
        // Swap the next and previous pointers
        previous = current->previous;
        current->previous = current->next;
        current->next = previous;

        // Move to the next node in the original list
        current = current->previous;
    }

    // previous now points to the last processed node, which is the new head
    return previous->previous;
}

// Function to print the doubly linked list
void printDLL(Node* head) { // Changed return type to void
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl; // Added newline for formatting
}

int main() {
    vector<int> arr = {3, 45, 1, 19, 32};
    Node* head = convertArr2DLL(arr);
    
    cout << "DLL before reversing: ";
    printDLL(head); // This prints the DLL before reversal
    
    // Reverse the list
    head = reverseDLL(head);

    cout << "DLL after reversing: ";
    printDLL(head); // This prints the DLL after reversal

    return 0;
}
