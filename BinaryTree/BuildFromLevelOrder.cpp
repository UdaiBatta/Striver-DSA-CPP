#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to build a binary tree from user input
Node* BinaryTree() {
    cout << "Enter the data of the node (enter -1 for NULL): ";
    int data;
    cin >> data;

    if (-1 == data) {
        return nullptr;
    }

    Node* root = new Node(data);

    cout << "Enter the data for the left child of " << data << endl;
    root->left = BinaryTree();

    cout << "Enter the data for the right child of " << data << endl;
    root->right = BinaryTree();

    return root;
}

void LevelOrderTraversal(Node* root){
    if (root == nullptr) return;  // Check if the tree is empty

    queue<Node*> q;
    q.push(root);
    q.push(NULL);  

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;  
            if (!q.empty()) {
                q.push(NULL);  
            }
        } else {
            cout << temp->data << " ";
            // Push left and right children, if they exist
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void PreOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void BuildFromLevelOrder(Node* &root){
    queue<Node*> q;
    cout<<"Enter the value for root"<<endl;
    int val;
    cin >> val;
    root = new Node(val);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter the value for the left child node of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the value for the right child node  of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}


int main() {
    Node* root = nullptr;

    // Build the binary tree starting from the root
    // root = BinaryTree();
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // Perform level-order traversal and print the nodes
    // cout << "Printing the Level-order Traversal: "<<endl;
    // ReverseLevelOrderTraversal(root);
    // cout<<"Inorder traversal value is "<<endl;
    BuildFromLevelOrder(root);
    LevelOrderTraversal(root);

    return 0;
}

