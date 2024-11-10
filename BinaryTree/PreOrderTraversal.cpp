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

void ReverseLevelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    stack<int> s;

    q.push(root);

    // Standard level-order traversal
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Push the node data into the stack instead of printing
        s.push(temp->data);

        // Enqueue right child first, then left child
        // This ensures that left nodes are popped first from the stack
        if (temp->right) {
            q.push(temp->right);
        }
        if (temp->left) {
            q.push(temp->left);
        }
    }

    // Pop elements from the stack to print them in reverse level-order
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
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


int main() {
    Node* root = nullptr;

    // Build the binary tree starting from the root
    root = BinaryTree();
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // Perform level-order traversal and print the nodes
    cout << "Printing the Level-order Traversal: "<<endl;
    // ReverseLevelOrderTraversal(root);
    cout<<"Inorder traversal value is "<<endl;
    PreOrder(root);

    return 0;
}

