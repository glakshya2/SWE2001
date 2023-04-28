#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    int n, small = 0;
    cout << "Enter size of array\n";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        small = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[small] > arr[j])
            {
                small = j;
            }
        }
        if (small != i)
            swap(arr[small], arr[i]);
    }
}