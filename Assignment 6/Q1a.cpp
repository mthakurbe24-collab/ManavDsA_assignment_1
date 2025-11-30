#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* prev;
};


class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head, nullptr};
        if (head) head->prev = newNode;
        head = newNode;
    }


    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int target, int value) {
        Node* temp = head;
        while (temp && temp->data != target)
            temp = temp->next;
        if (temp) {
            Node* newNode = new Node{value, temp->next, temp};
            if (temp->next) temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    void insertBefore(int target, int value) {
        Node* temp = head;
        while (temp && temp->data != target)
            temp = temp->next;
        if (temp) {
            Node* newNode = new Node{value, temp, temp->prev};
            if (temp->prev) temp->prev->next = newNode;
            else head = newNode; 
            temp->prev = newNode;
        }
    }

    
    void deleteNode(int value) {
        Node* temp = head;
        while (temp && temp->data != value) temp = temp->next;
        if (!temp) return; 
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next; 
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }

  
    void searchNode(int value) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << value << " not found!\n";
    }

 
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, value, target;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
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
                dll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: "; cin >> value;
                dll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter target node: "; cin >> target;
                cout << "Enter new value: "; cin >> value;
                dll.insertAfter(target, value);
                break;
            case 4:
                cout << "Enter target node: "; cin >> target;
                cout << "Enter new value: "; cin >> value;
                dll.insertBefore(target, value);
                break;
            case 5:
                cout << "Enter node to delete: "; cin >> value;
                dll.deleteNode(value);
                break;
            case 6:
                cout << "Enter node to search: "; cin >> value;
                dll.searchNode(value);
                break;
            case 7:
                dll.display();
                break;
        }

    } while(choice != 0);

    return 0;
}
