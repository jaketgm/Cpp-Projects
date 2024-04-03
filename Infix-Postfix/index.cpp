#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cctype>
#include <cmath>
#include <sstream> // Include for stringstream

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void printStackAndQueue(stack<char> s, queue<string> q) {
    cout << "Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\nQueue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n\n";
}

string infixToPostfix(string infix) {
    stack<char> s;
    queue<string> q;
    string postfix = "";

    for (size_t i = 0; i < infix.length(); ++i) {
        char c = infix[i];

        if (isdigit(c)) {
            string number = "";
            while (i < infix.length() && isdigit(infix[i])) {
                number += infix[i];
                ++i;
            }
            --i; // Correcting the index after the inner loop
            q.push(number);
            printStackAndQueue(s, q); // Print after adding a number to the queue
        }
        else if (c == '(') {
            // Insert a multiplication operator if there's a number before '('
            if (i > 0 && isdigit(infix[i - 1])) {
                while (!s.empty() && precedence(s.top()) >= precedence('*')) {
                    q.push(string(1, s.top()));
                    s.pop();
                    printStackAndQueue(s, q); // Print after each pop and push
                }
                s.push('*');
                printStackAndQueue(s, q); // Print after adding '*' to the stack
            }
            s.push(c);
            printStackAndQueue(s, q); // Print after adding '(' to the stack
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                q.push(string(1, s.top()));
                s.pop();
                printStackAndQueue(s, q); // Print after each pop and push
            }
            s.pop();
            printStackAndQueue(s, q); // Print after popping '(' from the stack
            // Insert a multiplication operator if there's a number after ')'
            if (i < infix.length() - 1 && isdigit(infix[i + 1])) {
                while (!s.empty() && precedence(s.top()) >= precedence('*')) {
                    q.push(string(1, s.top()));
                    s.pop();
                    printStackAndQueue(s, q); // Print after each pop and push
                }
                s.push('*');
                printStackAndQueue(s, q); // Print after adding '*' to the stack
            }
        }
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                q.push(string(1, s.top()));
                s.pop();
                printStackAndQueue(s, q); // Print after each pop and push
            }
            s.push(c);
            printStackAndQueue(s, q); // Print after adding an operator to the stack
        }
    }

    while (!s.empty()) {
        q.push(string(1, s.top()));
        s.pop();
        printStackAndQueue(s, q); // Print after moving remaining elements from the stack to the queue
    }

    while (!q.empty()) {
        postfix += q.front() + " ";
        q.pop();
    }

    return postfix;
}