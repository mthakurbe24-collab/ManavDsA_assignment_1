#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
};


class CircularDoublyLinkedList {
    Node* head;
public:
    CircularDoublyLinkedList() {
        head = nullptr;
    }

    
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }

    
    void insertAfter(int target, int value) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == target) {
                Node* newNode = new Node{value, temp->next, temp};
                temp->next->prev = newNode;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

 
    void insertBefore(int target, int value) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == target) {
                Node* newNode = new Node{value, temp, temp->prev};
                temp->prev->next = newNode;
                temp->prev = newNode;
                if (temp == head) head = newNode; 
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void deleteNode(int value) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == value) {
                if (temp->next == temp) { 
                    delete temp;
                    head = nullptr;
                    return;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == head) head = temp->next;
                delete temp;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

   
    void searchNode(int value) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node " << value << " not found!\n";
    }

   
    void display() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};


int main() {
    CircularDoublyLinkedList cdll;
    int choice, value, target;

    do {
        cout << "\n--- Circular Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: "; cin >> value;
                cdll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: "; cin >> value;
                cdll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter target node: "; cin >> target;
                cout << "Enter new value: "; cin >> value;
                cdll.insertAfter(target, value);
                break;
            case 4:
                cout << "Enter target node: "; cin >> target;
                cout << "Enter new value: "; cin >> value;
                cdll.insertBefore(target, value);
                break;
            case 5:
                cout << "Enter node to delete: "; cin >> value;
                cdll.deleteNode(value);
                break;
            case 6:
                cout << "Enter node to search: "; cin >> value;
                cdll.searchNode(value);
                break;
            case 7:
                cdll.display();
                break;
        }
    } while(choice != 0);

    return 0;
}
