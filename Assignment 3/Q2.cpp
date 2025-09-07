#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    char arr[MAX];
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

    void push(char c) {
        if (!isFull()) {
            arr[++top] = c;
        }
    }

};

int main() {
    string str = "DataStructure";
    Stack s;

    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }
   cout << "Stack elements reversed: ";
    for (int i = str.length(); i >= 0; i--) {
        cout << str[i];
    }


    return 0;
}

