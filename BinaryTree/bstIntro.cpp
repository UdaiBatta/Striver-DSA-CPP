#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int data1){
        data = data1;
        right = nullptr;
        left = nullptr;
    }
};

void insertIntoBst(Node* &root , int d){
    if(root == nullptr){
        root = new Node(d);
        return root;
    }
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        insertIntoBst(root , data);
        cin>>data;
    }
}

int main(){
    Node* root = NULL:

    cout<<"Enter the data to create BST"<<endl;
    takeInput(root);
}