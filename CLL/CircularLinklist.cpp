#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = nullptr;
    }
};

void insertNode(Node* &tail , int d , int element){
    

    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{

        Node* curr = tail;
        while(curr->data == element){
            curr = curr->next;
        }
    Node* temp = new Node(d);
    temp->next = curr->next;
    curr->next = temp;
    }
}

void PrintNode(Node* tail){
    if (tail == NULL){
        cout<<"The list is empty"<<endl;
        return;
    }
    
    Node* temp = tail;
    do
    {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while (tail != temp);
    {
    cout<<endl;
    }
}

int main(){
    Node* tail = NULL;

    insertNode(tail, 3 , 9);
    PrintNode(tail);

    insertNode(tail , 5 , 14);
    PrintNode(tail);

    insertNode(tail , 7 , 19);
    PrintNode(tail);

}


