#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void printLL(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* convertArr2LL(vector<int> arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;  // Move the mover to the next node.
    }
    return head;
}

Node* removeHead(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* DeleteEl(Node* head, int el) {
    if (head == nullptr) return head;

    // Case 1: The element is found at the head of the list.
    if (head->data == el) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Case 2: The element is found somewhere in the middle or end.
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->data == el) {
            prev->next = temp->next;  // Fix: Correct pointer adjustment.
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);

    // Delete element 7 from the list.
    head = DeleteEl(head, 7);

    // Print the modified linked list.
    printLL(head);  // Expected Output: 12 5 8

    return 0;
}
