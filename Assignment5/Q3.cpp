#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void findMiddle() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;        
            fast = fast->next->next;  
        }
        cout << "Middle Node: " << slow->data << endl;
    }

 
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << "Linked List: ";
    list.display();

    list.findMiddle();

    return 0;
}


