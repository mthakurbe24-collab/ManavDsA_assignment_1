#include <iostream>
using namespace std;


struct Node {
    char data;
    Node* next;
    Node* prev;
};


class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }


    void insert(char ch) {
        Node* newNode = new Node{ch, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

   
    bool isPalindrome() {
        if (!head || !head->next) return true;

     
        Node* left = head;
        Node* right = head;

        while (right->next)
            right = right->next;

    
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }

        return true;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insert('r');
    dll.insert('a');
    dll.insert('c');
    dll.insert('e');
    dll.insert('c');
    dll.insert('a');
    dll.insert('r');

    if (dll.isPalindrome())
        cout << "The doubly linked list is a palindrome.\n";
    else
        cout << "The doubly linked list is NOT a palindrome.\n";

    return 0;
}

