#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, size;
public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return -1;
        }
        int val = arr[front++];
        if (front > rear) front = rear = -1; // reset if empty
        return val;
    }

    int getFront() {
        if (!isEmpty()) return arr[front];
        return -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    int getSize() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    ~Queue() {
        delete[] arr;
    }
};

void interleaveQueue(Queue &q) {
    int n = q.getSize();
    if (n % 2 != 0) {
        cout << "Queue size must be even for interleaving.\n";
        return;
    }

    int half = n / 2;
    Queue firstHalf(half);

  
    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(q.dequeue());
    }

    for (int i = 0; i < half; i++) {
        q.enqueue(firstHalf.dequeue());  
        q.enqueue(q.dequeue());         
    }
}

int main() {
    int n, value;
    cout << "Enter number of elements (even number): ";
    cin >> n;

    Queue q(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}


