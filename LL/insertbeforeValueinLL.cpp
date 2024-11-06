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

Node* removeTail(Node* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

Node* DeleteK(Node* head, int k) {
    if (head == nullptr) return head;
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 1;
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (cnt == k) {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    return head;
}

Node* insertBeforeValue(Node* head , int el , int val){
    if(head == NULL){
        return NULL;
    }
    if(head->data == 1){
        return new Node(el , head);
    }

    Node* temp = head;
    while(temp->next != NULL){

        if (temp->next->data = val){
            Node* x = new Node(el ,temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
        }
        return head;
    }

int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);

    // head = removeTail(head);  // Remove the tail (7).
    head = insertBeforeValue(head , 100 , 5);  // Delete the 2nd element (5).
    
    printLL(head);  // Output should be: 12 8

    return 0;
}
