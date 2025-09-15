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

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
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

    void insertBefore(int newValue, int target) {
        if (!head) return;
        if (head->data == target) {
            insertAtBeginning(newValue);
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != target) temp = temp->next;
        if (temp->next) {
            Node* newNode = new Node{newValue, temp->next};
            temp->next = newNode;
        }
    }

    void insertAfter(int newValue, int target) {
        Node* temp = head;
        while (temp && temp->data != target) temp = temp->next;
        if (temp) {
            Node* newNode = new Node{newValue, temp->next};
            temp->next = newNode;
        }
    }

    void deleteFromBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNode(int value) {
        if (!head) return;
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) temp = temp->next;
        if (temp->next) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
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
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, target;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter new value: ";
                cin >> value;
                cout << "Insert before which node? ";
                cin >> target;
                list.insertBefore(value, target);
                break;
            case 4:
                cout << "Enter new value: ";
                cin >> value;
                cout << "Insert after which node? ";
                cin >> target;
                list.insertAfter(value, target);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                list.searchNode(value);
                break;
            case 9:
                list.display();
                break;
        }
    } while (choice != 0);

    return 0;
}
