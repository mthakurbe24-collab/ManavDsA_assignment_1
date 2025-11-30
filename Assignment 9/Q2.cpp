#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int arr[101];
    int size;

    void heapifyDown(int i) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (left <= size && arr[left] > arr[largest])
            largest = left;

        if (right <= size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) {
        int parent = i / 2;

        if (i > 1 && arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            heapifyUp(parent);
        }
    }

public:
    PriorityQueue() {
        size = 0;
    }

    void push(int value) {
        size++;
        arr[size] = value;
        heapifyUp(size);
    }

    int pop() {
        if (size == 0) {
            cout << "Queue empty" << endl;
            return -1;
        }

        int highest = arr[1];
        arr[1] = arr[size];
        size--;
        heapifyDown(1);

        return highest;
    }

    int top() {
        if (size == 0) {
            cout << "Queue empty" << endl;
            return -1;
        }
        return arr[1];
    }

    bool empty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void print() {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(40);
    pq.push(10);
    pq.push(50);
    pq.push(30);
    pq.push(60);

    cout << "Priority Queue: ";
    pq.print();

    cout << "Top element: " << pq.top() << endl;

    cout << "Pop: " << pq.pop() << endl;
    cout << "After pop: ";
    pq.print();

    cout << "Pop: " << pq.pop() << endl;
    cout << "After pop: ";
    pq.print();

    return 0;
}