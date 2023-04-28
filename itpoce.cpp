#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

template <typename t>
class stack
{
    int top, n;
    t *a;

public:
    stack(int);
    bool isEmpty();
    bool isFull();
    void push(t);
    t pop();
    void display();
    t peek();
};

template <typename t>
stack<t>::stack(int x)
{
    n = x;
    a = new t[x];
    top = -1;
}

template <typename t>
bool stack<t>::isEmpty()
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

template <typename t>
bool stack<t>::isFull()
{
    if (top == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename t>
void stack<t>::push(t n)
{
    top = top + 1;
    a[top] = n;
}

template <typename t>
t stack<t>::pop()
{
    top = top - 1;
    return a[top + 1];
}

template <typename t>
void stack<t>::display()
{
    for (int i = 0; i <= top; i++)
    {
        cout << a[i] << "\n";
    }
}

template <typename t>
t stack<t>::peek()
{
    return a[top];
}

int precede(char reading)
{
    int result;
    switch (reading)
    {
    case '^':
        result = 3;
        break;
    case '*':
        result = 2;
        break;
    case '/':
        result = 2;
        break;
    case '+':
        result = 1;
        break;
    case '-':
        result = 1;
        break;
    default:
        result = 0;
    }
    return result;
}

bool operatorCheck(char read)
{
    if (read == '(' || read == ')' || read == '^' || read == '/' || read == '*' || read == '+' || read == '-')
    {
        return true;
    }
    else
    {
        return false;
    }
}

double calc(double op1, double op2, char oper)
{
    double result;
    switch (oper)
    {
    case '/':
        result = op1 / op2;
        break;
    case '*':
        result = op1 * op2;
        break;
    case '^':
        result = pow(op1, op2);
        break;
    case '+':
        result = op1 + op2;
        break;
    case '-':
        result = op1 - op2;
        break;
    }
    return result;
}

bool negativeCheck(char reading, char inputArray[], int i)
{
    if (reading == '-' && isdigit(inputArray[i + 1]) && (operatorCheck(inputArray[i - 1]) || inputArray[i - 1] == '(' || inputArray[i - 1] == ')'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int pushClosing(string postFix[], int k, string input, stack<char> &operatorStack)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (operatorStack.peek() != '(')
        {
            postFix[k] = operatorStack.pop();
            k++;
        }
        else
        {
            operatorStack.pop();
            break;
        }
    }
    return k;
}

int lowerPre(int rPre, int sPre, string postFix[], stack<char> &operatorStack, char reading, int k)
{
    while (rPre <= sPre)
    {
        postFix[k] = operatorStack.pop();
        k++;
        sPre = precede(operatorStack.peek());
    }
    operatorStack.push(reading);
    return k;
}

int pushOperand(char reading, string &temp, char inputArray[], int i, string input, string postFix[], int k)
{
    if (isdigit(reading) || reading == '-' || reading == '.')
    {
        temp = temp + reading;
        if (!isdigit(inputArray[i + 1]) && (i == input.length() - 1 || inputArray[i + 1] != '.'))
        {
            postFix[k] = temp;
            temp = "";
            k++;
        }
    }
    else
    {
        postFix[k] = reading;
        k++;
    }
    return k;
}

int finalPush(stack<char> &operatorStack, string postFix[], int k)
{
    for (int i = 0; !operatorStack.isEmpty(); i++)
    {
        postFix[k] = operatorStack.pop();
        k++;
    }
    return k;
}

void printPost(int k, string postFix[])
{
    cout << "Postfix: ";
    for (int i = 0; i < k; i++)
    {
        cout << postFix[i]<<" ";
    }
    cout << "\n";
}

int convert(string input, string postFix[], stack<char> &operatorStack)
{
    string temp;
    char inputArray[input.length()], reading;
    strcpy(inputArray, input.c_str());
    int rPre, sPre, k = 0;
    for (int i = 0; i < input.length(); i++)
    {
        reading = inputArray[i];
        if (operatorCheck(reading) && !negativeCheck(reading, inputArray, i))
        {
            rPre = precede(inputArray[i]);
            sPre = precede(operatorStack.peek());
            if (reading == '(')
            {
                operatorStack.push('(');
            }
            else if (reading == ')')
            {
                k = pushClosing(postFix, k, input, operatorStack);
            }
            else if (rPre <= sPre)
            {
                k = lowerPre(rPre, sPre, postFix, operatorStack, reading, k);
            }
            else if (rPre > sPre)
            {
                operatorStack.push(reading);
            }
        }
        else
        {
            k = pushOperand(reading, temp, inputArray, i, input, postFix, k);
        }
    }

    k = finalPush(operatorStack, postFix, k);
    printPost(k, postFix);
    return k;
}

void evaluate(int k, string postFix[])
{
    double output, op1, op2;
    stack<double> operandStack(k + 1);
    for (int i = 0; i < k; i++)
    {

        if (isdigit(postFix[i][0]) || isdigit(postFix[i][1]))
        {
            operandStack.push(stod(postFix[i]));
        }
        else
        {
            op2 = operandStack.pop();
            op1 = operandStack.pop();
            output = calc((op1), (op2), postFix[i][0]);
            operandStack.push(output);
        }
    }

    cout << "output: " << output;
}

int main(void)
{
    int k, s;
    string input, temp = "";
    cout << "Enter input\n";
    cin >> input;
    string postFix[input.size()];
    stack<char> operatorStack(input.size());
    k = convert(input, postFix, operatorStack);
    if (isdigit(postFix[0][0]))
    {
        evaluate(k, postFix);
    }
    return 0;
}