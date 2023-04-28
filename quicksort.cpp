#include <iostream>

using namespace std;

void quickSort(int arr[], int i, int j)
{
	bool flag = true;
	for(int k = i; k< j; k++){
		if(arr[k]>arr[k+1]){
			flag = false;
			break;
		}
	}
	if(flag){
		return;
	}
	j--;
	int p = i;
	int n = j;
	i++;
	while (i <= j)
	{
		if (arr[i] <= arr[p])
		{
			i++;
		}
		else if (arr[j] > arr[p])
		{
			j--;
		}
		else if(arr[i]>arr[p] && arr[j]<arr[p]){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[p];
	arr[p] = arr[j];
	arr[j] = temp;
	quickSort(arr, p, j);
	quickSort(arr, j + 1, n);
}

int main(void)
{
	int n;
	cout << "Enter size";
	cin >> n;
	int arr[n];
	cout << "Enter elements";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	quickSort(arr, 0, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
}