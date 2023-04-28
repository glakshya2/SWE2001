#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

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

int main(void)
{
    int rPre, sPre, i, j = 0, k = 0;
    string input, temp = "";
    char reading;
    cout << "Enter input\n";
    cin >> input;
    reverse(input.begin(), input.end());
    string preFix[input.length()];
    stack<char> operatorStack;
    char inputArray[input.length()];
    strcpy(inputArray, input.c_str());
    for (int i = 0; i < input.length(); i++)
    {
        reading = inputArray[i];
        if (operatorCheck(reading))
        {
            rPre = precede(inputArray[i]);
            if (!operatorStack.empty())
            {
                sPre = precede(operatorStack.top());
            }
            else
            {
                sPre = 0;
            }
            if (reading == ')')
            {
                operatorStack.push(')');
            }
            else if (reading == '(')
            {
                for (int i = 0; i < input.length(); i++)
                {
                    if (operatorStack.top() != ')')
                    {
                        preFix[k] = operatorStack.top();
                        operatorStack.pop();
                        k++;
                    }
                    else
                    {
                        operatorStack.top();
                        operatorStack.pop();
                        break;
                    }
                }
            }
            else if (rPre <= sPre)
            {
                while (rPre <= sPre)
                {
                    preFix[k] = operatorStack.top();
                    operatorStack.pop();
                    k++;
                    if (!operatorStack.empty())
                    {
                        sPre = precede(operatorStack.top());
                    }
                    else
                    {
                        sPre = 0;
                    }
                }
                operatorStack.push(reading);
            }
            else if (rPre > sPre)
            {
                operatorStack.push(reading);
            }
        }
        else
        {
            if (isdigit(reading))
            {
                temp = temp + reading;
                if (!isdigit(inputArray[i + 1]) || i == input.length() - 1)
                {
                    preFix[k] = temp;
                    temp = "";
                    k++;
                }
            }
            else
            {
                preFix[k] = reading;
                k++;
            }
        }
    }
    for (int i = 0; !operatorStack.empty(); i++)
    {
        preFix[k] = operatorStack.top();
        operatorStack.pop();
        k++;
    }

    string preFix2[sizeof(preFix) / sizeof(preFix[0])];

    int start = 0, end = 0;

    while (preFix[end] != "\0" && end < input.length())
    {
        end++;
    }
    end--;
    int end2 = end;
    for (i = 0; i < input.length(); i++)
    {
        preFix2[i] = preFix[i];
    }
    while (preFix[start] != "\0" && start < end)
    {
        string temp = preFix[start];
        preFix[start] = preFix[end];
        preFix[end] = temp;
        start++;
        end--;
    }
    cout << "PreFix: ";
    for (int i = 0; i <= k; i++)
    {
        cout << preFix[i];
    }
}