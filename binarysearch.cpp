#include <iostream>
using namespace std;
class array
{
	int n, *arr, high, middle = -1, low = 0;

public:
	array();
	void sort();
	int search(int);
};

int setmid(int high, int low)
{
	int mid = low + (high - 1) / 2;
	return mid;
}

array::array()
{
	cout << "Enter size of array \n";
	cin >> n;
	arr = new int[n];
	cout << "Enter array elements";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void array::sort()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int array::search(int x)
{
	int ans = -1;
	cout << endl;
	low = 0;
	high = n - 1;
	middle = setmid(high, low);
	for (int i = low; i <= high; i++)
	{
		if (arr[middle] == x)
		{
			ans = middle;
		}
		else if (arr[middle] > x)
		{
			high = middle - 1;
			middle = setmid(high, low);
		}
		else if (arr[middle] < x)
		{
			low = middle + 1;
			middle = setmid(high, low);
		}
	}
	return ans;
}

int main(void)
{
	array a;
	int x;
	cout << "Enter element to search for\n";
	cin >> x;
	a.sort();
	int ans = a.search(x);
	if (ans != -1)
	{
		cout << "Answer: " << ans;
	}
	else
	{
		cout << "not found";
	}
}