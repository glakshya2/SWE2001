#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

double calc(double op1, double op2, char oper)
{
    double result;
    switch (oper)
    {
    case '/':
        result = op2 / op1;
        break;
    case '*':
        result = op1 * op2;
        break;
    case '^':
        result = pow(op2, op1);
        break;
    case '+':
        result = op1 + op2;
        break;
    case '-':
        result = op2 - op1;
        break;
    }
    return result;
}

int main(void)
{
    string input;
    cin>>input;
    string preFix[input.length()];
    char preFixArray[input.length()];
    strcpy(preFixArray, input.c_str());
    for(int i=0; i<input.length(); i++){
        preFix[i]+=preFixArray[i];
    }
    int num = sizeof(preFix)/sizeof(preFix[0]);
     reverse(preFix, preFix + num);   
    double output, op1, op2;
    stack<double> operandStack;
    for (int i = 0; i < input.size(); i++)
    {
        if (isdigit(preFix[i][0]))
        {
            operandStack.push(stod(preFix[i]));
        }
        else
        {
            op2 = operandStack.top();
            operandStack.pop();
            op1 = operandStack.top();
            operandStack.pop();
            output = calc((op1), (op2), preFix[i][0]);
            operandStack.push(output);
        }
    }
    cout << "output: " << output;
}