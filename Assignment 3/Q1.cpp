#include <iostream>
using namespace std;

#define MAX 5  

class Stack {
private:
    int stack[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }


    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            stack[++top] = value;
            cout << value << " pushed onto stack" << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop" << endl;
        } else {
            cout << stack[top--] << " popped from stack" << endl;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element" << endl;
        } else {
            cout << "Top element: " << stack[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;
    bool running = true;

    while (running) {
        cout << "\n--- Stack Operations Menu ---\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case 4:
                cout << (s.isFull() ? "Stack is full\n" : "Stack is not full\n");
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.peek();
                break;
            case 7:
                running = false;
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

