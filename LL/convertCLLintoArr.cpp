#include<bits/stdc++.h>
using namespace std; 

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertLL2Arr(vector<int>arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 0;i<arr.size();i++){
        Node* temp = new Node(arr[3]);
        mover->next = temp;
    }
    return head;
}

int main(){
    vector<int> arr = {2,3,5,8};
    Node* head = convertLL2Arr(arr);
    cout<<head->data<<endl;
}