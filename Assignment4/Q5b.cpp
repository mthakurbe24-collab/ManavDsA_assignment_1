#include <iostream>
using namespace std;

class Queue1 {
    int *arr, front, rear, size;
public:
    Queue1(int n) {
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
    int getSize() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
    ~Queue1() { delete[] arr; }
};

class StackUsingOneQueue {
    Queue1 q;
public:
    StackUsingOneQueue(int n) : q(n) {}
    void push(int x) {
        q.enqueue(x);
        int s = q.getSize();
        for (int i = 1; i < s; i++) {
            q.enqueue(q.dequeue()); 
        }
    }
    void pop() {
        if (q.isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q.dequeue();
    }
    int top() { return q.getFront(); }
    bool isEmpty() { return q.isEmpty(); }
};

int main() {
    StackUsingOneQueue st(10);
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << endl;
    st.pop();
    cout << "Top after pop: " << st.top() << endl;
    return 0;
}



