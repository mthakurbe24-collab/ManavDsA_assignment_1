#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *right;
    Node *left;

    Node(int val) {
        data = val;
        right = left = NULL;
    }
};

class BST {
public:
    Node *root;
    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int val) {
        if (!node) return new Node(val);
        if (val == node->data) return node;
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

    Node *findMin(Node *root) {
        while (root->left != NULL)
            root = root->left;
        return root;
    }

    Node *findMax(Node *root) {
        while (root->right != NULL)
            root = root->right;
        return root;
    }

    Node *deleteNode(Node *root, int val) {
        if (root == NULL)
            return root;
        if (val < root->data)
            root->left = deleteNode(root->left, val);
        else if (val > root->data)
            root->right = deleteNode(root->right, val);
        else {
            if (root->left == NULL) {
                Node *temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    int maxDepth(Node *root) {
        if (root == NULL)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }

    int minDepth(Node *root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL)
            return 1 + minDepth(root->right);
        if (root->right == NULL)
            return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }

    void inorder(Node *root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    BST tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 8);
    tree.root = tree.insert(tree.root, 11);
    tree.root = tree.insert(tree.root, 9);
    tree.root = tree.insert(tree.root,15);
    tree.root = tree.insert(tree.root,10);

    tree.root = tree.deleteNode(tree.root, 8);
    tree.inorder(tree.root);
    cout << endl;
    cout << "Max Depth of Tree is: " << tree.maxDepth(tree.root) << endl;
    cout << "Min Depth of Tree is: " << tree.minDepth(tree.root) << endl;

    return 0;
}