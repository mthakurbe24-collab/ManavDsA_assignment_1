#include <iostream>
using namespace std;

class Queue {
    char *arr;
    int front, rear, size;
public:
    Queue(int n) {
        size = n;
        arr = new char[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(char ch) {
        if (rear == size - 1) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = ch;
    }

    void dequeue() {
        if (isEmpty()) return;
        front++;
        if (front > rear) front = rear = -1;
    }

    char getFront() {
        if (!isEmpty()) return arr[front];
        return '\0';
    }

    ~Queue() {
        delete[] arr;
    }
};

void firstNonRepeating(string str) {
    int freq[256] = {0};
    Queue q(str.length());

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        freq[ch]++;
        q.enqueue(ch);

        while (!q.isEmpty() && freq[q.getFront()] > 1) {
            q.dequeue();
        }

        if (q.isEmpty())
            cout << "-1 ";
        else
            cout << q.getFront() << " ";
    }
    cout << "\n";
}

int main() {
    string str;
    cout << "Enter characters (no spaces): ";
    cin >> str;

    cout << "Output: ";
    firstNonRepeating(str);

    return 0;
}


