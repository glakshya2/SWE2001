#include <iostream>

using namespace std;
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void shellSort(int arr[], int n)
{
    for (int interval = n / 2; interval >= 1; interval /= 2)
    {
        int i = 0, j = interval;
        while (j < n)
        {
            if (arr[j] < arr[i])
            {
                swap(arr, i, j);
                int k = i;
                while (k - interval >= 0 && arr[k] < arr[k - interval])
                {
                    swap(arr, k, k - interval);
                    k -= interval;
                }
            }
            i++;
            j++;
        }
    }
}

int main(void)
{
    cout << "Enter size\n";
    int n;
    cin >> n;
    cout << "Enter elements\n";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    shellSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}