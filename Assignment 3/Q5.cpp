#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(int val) { if (top < MAX - 1) arr[++top] = val; }
    int pop() { return (top >= 0) ? arr[top--] : 0; }
    bool isEmpty() { return top == -1; }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Custom power function without math library
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int evaluatePostfix(const string &postfix) {
    Stack s;
    for (char ch : postfix) {
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');  // Convert char digit to int
        }
        else if (isOperator(ch)) {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(power(val1, val2)); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;
    cout << "Result = " << evaluatePostfix(postfix);
    return 0;
}

