#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    bool isBSTUtil(Node* node, Node* minNode, Node* maxNode) {
        if (!node) return true;
        if ((minNode && node->data <= minNode->data) || 
            (maxNode && node->data >= maxNode->data))
            return false;
        return isBSTUtil(node->left, minNode, node) && 
               isBSTUtil(node->right, node, maxNode);
    }

    bool isBST() {
        return isBSTUtil(root, nullptr, nullptr);
    }
};

int main() {
    BST tree;
    tree.root = tree.insert(tree.root, 4);
    tree.root = tree.insert(tree.root, 2);
    tree.root = tree.insert(tree.root, 6);
    tree.root = tree.insert(tree.root, 1);
    tree.root = tree.insert(tree.root, 3);
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 7);

    if (tree.isBST())
        cout << "The given binary tree is a BST.";
    else
        cout << "The given binary tree is not a BST.";
    return 0;
}