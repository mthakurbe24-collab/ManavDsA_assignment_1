#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

DNode* head = nullptr;

void insert(int value) {
    DNode* newNode = new DNode();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (!head) {
        head = newNode;
        return;
    }
    DNode* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

int getSize() {
    int count = 0;
    DNode* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    cout << "Size of Doubly Linked List: " << getSize() << endl;
    return 0;
}
