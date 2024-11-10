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

    if (data == -1) {
        return nullptr;
    }

    Node* root = new Node(data);

    cout << "Enter the data for the left child of " << data << endl;
    root->left = BinaryTree();

    cout << "Enter the data for the right child of " << data << endl;
    root->right = BinaryTree();

    return root;
}


int main() {
    Node* root = nullptr;

    // Build the binary tree starting from the root
    root = BinaryTree();
    //1 3 7 -1 -1 -1  24 745 -1 -1 89 68 -1 -1 -1 
    // Perform level-order traversal and print the nodes
    cout << "Level-order Traversal: ";

    return 0;
}

