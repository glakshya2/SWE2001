#include <iostream>
#include <queue>
using namespace std;

int returnNum(int x, int d, int max)
{
    int arr[max];
    for (int i = 0; i < max; i++)
    {
        arr[i] = x % 10;
        x /= 10;
    }
    return arr[d];
}

int returnSize(int x)
{

    int d = 0;
    while (x > 0)
    {
        x = x / 10;
        d++;
    }
    return d;
}

int main(void)
{
    int n;
    cout << "Enter size\n";
    cin >> n;
    int arr[n], sorted[n];
    queue<int> zero, one, two, three, four, five, six, seven, eight, nine;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int largest = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[largest] < arr[i])
        {
            largest = i;
        }
    }

    int d = returnSize(arr[largest]);

    for (int i = 0; i < d; i++)
    {
        int x = 0;
        for (int j = 0; j < n; j++)
        {
            int size = returnSize(arr[j]);
            int number = returnNum(arr[j], i, size);
            if (i + 1 > size)
            {
                zero.push(arr[j]);
            }
            else if (number == 0)
            {
                zero.push(arr[j]);
            }
            else if (number == 1)
            {
                one.push(arr[j]);
            }
            else if (number == 2)
            {
                two.push(arr[j]);
            }
            else if (number == 3)
            {
                three.push(arr[j]);
            }
            else if (number == 4)
            {
                four.push(arr[j]);
            }
            else if (number == 5)
            {
                five.push(arr[j]);
            }
            else if (number == 6)
            {
                six.push(arr[j]);
            }
            else if (number == 7)
            {
                seven.push(arr[j]);
            }
            else if (number == 8)
            {
                eight.push(arr[j]);
            }
            else if (number == 9)
            {
                nine.push(arr[j]);
            }
        }
        while (!zero.empty())
        {
            sorted[x] = zero.front();
            zero.pop();
            x++;
        }
        while (!one.empty())
        {
            sorted[x] = one.front();
            one.pop();
            x++;
        }
        while (!two.empty())
        {
            sorted[x] = two.front();
            two.pop();
            x++;
        }
        while (!three.empty())
        {
            sorted[x] = three.front();
            three.pop();
            x++;
        }
        while (!four.empty())
        {
            sorted[x] = four.front();
            four.pop();
            x++;
        }
        while (!five.empty())
        {
            sorted[x] = five.front();
            five.pop();
            x++;
        }
        while (!six.empty())
        {
            sorted[x] = six.front();
            six.pop();
            x++;
        }
        while (!seven.empty())
        {
            sorted[x] = seven.front();
            seven.pop();
            x++;
        }
        while (!eight.empty())
        {
            sorted[x] = eight.front();
            eight.pop();
            x++;
        }
        while (!nine.empty())
        {
            sorted[x] = nine.front();
            nine.pop();
            x++;
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = sorted[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << sorted[i] << "\t";
    }
    return 0;
}