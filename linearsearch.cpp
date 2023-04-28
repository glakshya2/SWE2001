#include<iostream>
using namespace std;
class array{
    int n, *arr;
    public:
    array(){
        cout<<"enter size of array\n";
	    cin>>n;
        arr = new int[n];
        for(int i=0; i<n; i++){
		    cin>>arr[i];
	    }
    }

    int search(int x){
        for(int i=0; i<n; i++){
    		if(arr[i]==x){
    			return i;
            }
        }
        return -1;
    }
};

int main(void){
	array a;
    int search;
	cout<<"enter element to be searched for\n";
	cin>>search;
    if(a.search(search)!=-1){
        cout<<a.search(search);
    }
    else{
        cout<<"not found";
    }    
}
