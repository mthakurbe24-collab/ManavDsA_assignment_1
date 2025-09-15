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

    // Insert at the end
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

    // Count occurrences of a key
    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        while (temp) {
            if (temp->data == key) count++;
            temp = temp->next;
        }
        return count;
    }

    // Delete all occurrences of a key
    void deleteOccurrences(int key) {
        // Remove from start if key matches
        while (head && head->data == key) {
            Node* del = head;
            head = head->next;
            delete del;
        }

        // Remove from the rest of the list
        Node* current = head;
        while (current && current->next) {
            if (current->next->data == key) {
                Node* del = current->next;
                current->next = current->next->next;
                delete del;
            } else {
                current = current->next;
            }
        }
    }

    // Display list
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
    int n, val, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << "Enter key to count and delete: ";
    cin >> key;

    int count = list.countOccurrences(key);
    cout << "Occurrences of " << key << " = " << count << endl;

    list.deleteOccurrences(key);

    cout << "List after deletion: ";
    list.display();

    return 0;
}

