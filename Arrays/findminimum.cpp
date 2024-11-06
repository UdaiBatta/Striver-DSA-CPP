#include<iostream>
using namespace std;

int showArray(int arr[], int n){
	for (int i = 0; i<n;i++){
		cout<<arr[i]<<endl;
	}
}

int minarrayElements(int arr[],int n){
	int min= 0;
	for(int i =0;i<n;i++){
		if(arr[i]<arr[min])
		min = i;
	}
	return arr[min];
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);  
    
    cout << "The array elements are: " << endl;
    showArray(arr, n);  
    
    int minElement = minarrayElements(arr, n);  
    cout << "The minimum element is: " << minElement << endl;z
    
    return 0;
}
