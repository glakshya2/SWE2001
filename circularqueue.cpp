#include <iostream>
using namespace std;

class cqueue
{
    int n, *a, rear = -1, front = -1;

public:
    cqueue();
    bool isFull();
    bool isEmpty();
    void enqueue(int);
    void dequeue();
    void display();
};

cqueue::cqueue()
{
    cout << "Enter size of array";
    cin >> n;
    a = new int[n];
}

bool cqueue::isFull()
{
    if ((front == 0 && rear == n - 1) || rear == (front - 1) % (n - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool cqueue::isEmpty()
{
    if (front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void cqueue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Already full\n";
    }
    else if (front == -1)
    {
        front++;
        rear++;
        a[rear] = x;
    }
    else if (rear == n - 1 && front != 0)
    {
        rear = 0;
        a[rear] = x;
    }
    else
    {
        rear++;
        a[rear] = x;
    }
}

void cqueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Already empty";
    }
    else if (rear == front)
    {
        front = rear = -1;
    }
    else if (front == n - 1)
    {
        front = 0;
    }
    else
    {
        a[front] = 0;
        front = (front + 1) % n;
    }
}

void cqueue::display()
{
    if (isEmpty())
    {
        cout << "Empty";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i];
        }
    }
}

int main(void)
{
    cqueue a;
    cout << "1.enqueue\n";
    cout << "2.dequeue\n";
    cout << "3.display\n";
    cout << "4.exit\n";
    int ch;
    cin >> ch;
    while (ch != 4)
    {
        switch (ch)
        {
        case 1:
            int in;
            cout << "Enter element\n";
            cin >> in;
            a.enqueue(in);
            break;
        case 2:
            a.dequeue();
            break;
        case 3:
            a.display();
            break;
        }
        cin >> ch;
    }
}