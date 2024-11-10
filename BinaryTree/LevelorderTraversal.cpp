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


int main() {
    Node* root = nullptr;

    // Build the binary tree starting from the root
    root = BinaryTree();
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // Perform level-order traversal and print the nodes
    cout << "Printing the Level-order Traversal: "<<endl;
    LevelOrderTraversal(root);

    return 0;
}

