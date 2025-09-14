#include <iostream>
using namespace std;

class Queue {
    int *arr, front, rear, size;
public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }
    bool isEmpty() { return front == -1; }
    void enqueue(int val) {
        if (rear == size - 1) return;
        if (front == -1) front = 0;
        arr[++rear] = val;
    }
    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[front++];
        if (front > rear) front = rear = -1;
        return val;
    }
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    ~Queue() { delete[] arr; }
};

class StackUsingTwoQueues {
    Queue q1, q2;
public:
    StackUsingTwoQueues(int n) : q1(n), q2(n) {}
    void push(int x) {
        if (q1.isEmpty()) {
            q1.enqueue(x);
            while (!q2.isEmpty()) q1.enqueue(q2.dequeue());
        } else {
            q2.enqueue(x);
            while (!q1.isEmpty()) q2.enqueue(q1.dequeue());
        }
    }
    void pop() {
        if (q1.isEmpty() && q2.isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        if (!q1.isEmpty()) q1.dequeue();
        else q2.dequeue();
    }
    int top() {
        if (!q1.isEmpty()) return q1.getFront();
        else return q2.getFront();
    }
    bool isEmpty() { return q1.isEmpty() && q2.isEmpty(); }
};

int main() {
    StackUsingTwoQueues st(10);
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << endl;
    st.pop();
    cout << "Top after pop: " << st.top() << endl;
    return 0;
}


