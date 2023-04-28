#include <iostream>
using namespace std;

int main(void)
{
    int arr1[] = {1,4,6,8,10,50};
    int arr2[] = {1,6,7,9,20,30,50};
    int s1 = sizeof(arr1)/sizeof(arr1[0]);
    int s2 = sizeof(arr2)/sizeof(arr2[0]);
    int j = 0, k = 0;
    while(j<s1 && k<s2){
        if(arr1[j]>arr2[k]){
            k++;
        }
        else if(arr1[j]<arr2[k]){
            j++;
        }
        else{
            cout<<arr1[j]<<" ";
            j++; k++;
        }
    }
}