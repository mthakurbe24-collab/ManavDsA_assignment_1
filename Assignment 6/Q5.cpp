#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (head == nullptr)
        return false; 

    Node* temp = head->next;

   
    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }


    if (temp == head)
        return true;

    return false;  
}

int main() {

    Node* head = new Node{10, nullptr};
    Node* second = new Node{20, nullptr};
    Node* third = new Node{30, nullptr};


    head->next = second;
    second->next = third;
    third->next = nullptr;  

 

    if (isCircular(head))
        cout << "The linked list is circular.\n";
    else
        cout << "The linked list is NOT circular.\n";

    return 0;
}

