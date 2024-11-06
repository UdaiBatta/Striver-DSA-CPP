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
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


Node* convertArr2LL(vector<int> arr) {
    if (arr.empty()) return NULL;  

    Node* head = new Node(arr[0]);  
    Node* mover = head;  

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); 
        mover->next = temp;  
    }
    return head;
}


Node* removeHead(Node* head) {
    if (head == NULL) { 
        return NULL;
    }
    Node* temp = head;
    head = head->next; 
    delete temp;  
    return head;  //
}

Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    
    Node* temp = head;
    while(temp-> next->next != NULL){
        temp = temp-> next;
    }
    delete temp -> next;
    temp->next = nullptr;

return head;
}

int main() {
    
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    head = removeTail(head);
    // head = removeHead(head);
    printLL(head);

    return 0;
}
