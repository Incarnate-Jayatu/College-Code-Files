#include <iostream>
using namespace std;

class Stack
{
private:
    int stack[100];
    int top;
    int size;

public:
    // Constructor
    Stack(int n)
    {
        size = n;
        top = -1;
    }

    // Push
    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        stack[top] = value;
    }

    // Pop
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        cout << "Deleted element: " << stack[top] << endl;
        top--;
    }

    // Peek
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Top element: " << stack[top] << endl;
    }

    // Display
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements: ";

        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();

    s.peek();

    s.pop();

    s.display();

    s.peek();

    return 0;
}