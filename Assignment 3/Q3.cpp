#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(char c) { if (top < MAX - 1) arr[++top] = c; }
    char pop() { return (top >= 0) ? arr[top--] : '\0'; }
    char peek() { return (top >= 0) ? arr[top] : '\0'; }
    bool isEmpty() { return top == -1; }
};

bool isBalanced(const string &expr) {
    Stack s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;
            char top = s.pop();
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '['))
                return false;
        }
    }
    return s.isEmpty();
}

int main() {
    string expr;
    cin >> expr;
    if (isBalanced(expr))
        cout << "Balanced";
    else
        cout << "Unbalanced";
    return 0;
}


