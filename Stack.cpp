#include <iostream>
using namespace std;

class stack
{
    int top;
    int *a, n;

public:
    stack(int);
    ~stack();
    bool isEmpty();
    bool isFull();
    void push(int);
    void pop();
    void display();
    void peek();
};

stack::stack(int x)
{
    n = x;
    a = new int[x];
    top = -1;
}

bool stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool stack::isFull()
{
    if (top == n - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void stack::push(int n)
{
    if (isFull())
    {
        cout << "Stack is already full";
    }
    else
    {
        top = top + 1;
        a[top] = n;
    }
}

void stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is already empty";
    }
    else
    {
        top = top - 1;
    }
}

void stack::display()
{
    if (!isEmpty())
    {
        for (int i = 0; i <= top; i++)
        {
            cout << a[i] << "\n";
        }
    }
    else
    {
        cout << "Stack is empty\n";
    }
}

void stack::peek()
{
    if (!isEmpty())
    {
        cout << a[top] << "\n";
    }
    else
    {
        cout << "stack is empty\n";
    }
}

stack::~stack()
{
    delete[] a;
}

int main(void)
{
    int ch, n;
    cout << "Enter size of stack\n";
    cin >> n;
    stack a(n);
    cout<<a.isEmpty();
    do
    {
        cout << "1) push\n";
        cout << "2) Pop\n";
        cout << "3) display\n";
        cout << "4) peek\n";
        cout << "5) Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int value;
            cout << "enter values to be entered\n";
            cin >> value;
            a.push(value);
            break;
        case 2:
            a.pop();
            break;
        case 3:
            a.display();
            break;
        case 4:
            a.peek();
            break;
        }
    } while (ch != 5);
    return 0;
}