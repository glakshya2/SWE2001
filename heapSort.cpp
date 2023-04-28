#include<iostream>

using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = (2*i)+1;
    int right = (2*i)+2;
    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n){
    for(int i = n/2 -1; i>=0; i--){
        heapify(arr, n, i);
    }
    for(int i = n-1; i>=0; i--){
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }
}
int main(void){
    cout<<"Enter size\n";
    int n;
    cin>>n;
    cout<<"Enter elements\n";
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    heapSort(arr, n);
    for(int i =0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
}