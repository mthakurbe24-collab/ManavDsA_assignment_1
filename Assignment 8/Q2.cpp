#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

class bstNode {
public: 
    int data;
    bstNode *left;
    bstNode *right;

    bstNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

bstNode* insert(bstNode* root, int data) {
    if (root == nullptr) {
        return new bstNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

bstNode* searchRecursive(bstNode* node, int key) {
        if (!node || node->data == key)
            return node;
        if (key < node->data)
            return searchRecursive(node->left, key);
        else
            return searchRecursive(node->right, key);
    }

int findMin(bstNode *root) {
    if (root == nullptr) {
        cerr << "Error: The tree is empty." << endl;
        return INT_MAX; 
    }

    bstNode *current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

int findMax(bstNode *root) {
    if (root == nullptr) {
        cerr << "Error: The tree is empty." << endl;
        return INT_MIN; 
    }

    bstNode *current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

bstNode *rightMost(bstNode *root){
    bstNode *ans = nullptr; 
    while(root != NULL){
        ans = root;
        root = root->right;
    }
    return ans;
}

bstNode *leftMost(bstNode *root){
    bstNode *ans = nullptr; 
    while(root != NULL){
        ans = root;
        root = root->left;
    }
    return ans;
}

vector<int> getPredSucc(bstNode *root, int key){
    bstNode *curr = root;
    bstNode *pred = NULL;
    bstNode *succ = NULL;
    
    while(curr != NULL){
        if(key < curr->data){
            succ = curr;
            curr = curr->left;
        } else if (key > curr->data){
            pred = curr;
            curr = curr->right;
        } else {
            if(curr->left != NULL) { 
                pred = rightMost(curr->left);
            }
            if(curr->right != NULL){
                succ = leftMost(curr->right);
            }
            break;
        }
    }
    
    vector<int> ans;
    if(pred == NULL){
        ans.push_back(INT_MIN); 
    } else {
        ans.push_back(pred->data);
    }

    if(succ == NULL){
        ans.push_back(INT_MAX); 
    } else {
        ans.push_back(succ->data);
    }
    return ans;
}


int main() {
    bstNode* root = nullptr; 

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    int key = 60;
    bstNode* foundNode = searchRecursive(root, key);
    if (foundNode) {
        cout << "Found node: " << foundNode->data << endl;
    } else {
        cout << "Node " << key << " not found." << endl;
    }
    cout << endl;

    int minVal = findMin(root);
    cout << "Minimum value in the BST: " << minVal << endl; 

    int maxVal = findMax(root);
    cout << "Maximum value in the BST: " << maxVal << endl; 

    cout << "\n--- Testing with an empty tree ---" << endl;
    bstNode* emptyRoot = nullptr;
    findMin(emptyRoot);
    findMax(emptyRoot);
    
    cout << "\n--- Predecessor and Successor for " << key << " ---" << endl;
    vector<int> ans = getPredSucc(root, key);

    if(ans[0] == INT_MIN){
        cout << "Predecessor: Not Found" << endl;
    } else {
        cout << "Predecessor: " << ans[0] << endl;
    }

    if(ans[1] == INT_MAX){
        cout << "Successor: Not Found" << endl;
    } else {
        cout << "Successor: " << ans[1] << endl;
    }

    return 0;
}