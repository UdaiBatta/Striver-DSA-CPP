#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1 , Node* next1 , Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size();i++){
        Node* temp = new Node(arr[i],nullptr , prev);
        prev->next = temp;
        prev = temp;
    }
    return head;}

void printDLL(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;}

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head-> next;
    
    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
          tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;}

Node* deleteK(Node* head , int k){
    if(head == NULL){
        return NULL;
    }
    int cnt = 0;
    Node* KNode = head;
    while(KNode != NULL){
        cnt++;
        if(cnt == k) break;
        KNode = KNode->next;
    }

    Node* prev = KNode->back;
    Node* front = KNode->next;

if (prev == nullptr && front == nullptr) {  // Only one node in the list
        delete KNode;
        return nullptr;
    } else if (prev == nullptr) {  // Delete head
        return deleteHead(head);
    } else if (front == nullptr) {  // Delete tail
        return deleteTail(head);
    }


    prev->next = front;
    front->back = prev;

    KNode->next = nullptr;
    KNode->back = nullptr;
    delete KNode;
    return head;

}

void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = temp;
        temp->back = nullptr;
        delete temp;
        return ;
}
prev->next = front;
front->back =  prev;    

temp->next = temp->back = nullptr;
delete temp;
}

Node* insertBeforeHead(Node* head, int val){
    Node* newhead = new Node(val , head , nullptr);
    head->back = newhead;

    return newhead;
}

int main(){
    vector <int> arr = { 12 , 5 , 23 , 9};
    Node* head = convertArr2DLL(arr);
    head = insertBeforeHead(head,10);
    printDLL(head);  
    return 0;
}