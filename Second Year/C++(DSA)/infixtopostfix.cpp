#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    char arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char x)
    {
        if (top == 99)
        {
            cout << "Stack Overflow";
            return;
        }
        arr[++top] = x;
    }

    char pop()
    {
        if (top == -1)
            return '\0';
        return arr[top--];
    }

    char peek()
    {
        if (top == -1)
            return '\0';
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix(string infix)
{
    Stack s;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if (ch == ' ')
            continue;
        // Operand
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            postfix += ch;
        }
        // Opening bracket
        else if (ch == '(')
        {
            s.push(ch);
        }
        // Closing bracket
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }

            if (!s.isEmpty())
                s.pop();
        }
        // Operator
        else
        {
            while (!s.isEmpty() && s.peek() != '(' && (precedence(s.peek()) > precedence(ch) || (precedence(s.peek()) == precedence(ch) && ch != '^')))
            {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }
    // Pop remaining operators
    while (!s.isEmpty())
    {
        postfix += s.pop();
    }
    return postfix;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin>>infix;
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}