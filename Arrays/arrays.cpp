#include<iostream>
using namespace std;

void printArray(int arr[],int n){
	
	for(int i=0;i<n;i++ ){
		cout<<arr[i]<< " ";
	}cout<<endl;
}

void swapAlternate(int arr[],int size){
	
	for(int i = 0;i<size;i++){
		if(i+1<size){
			swap(arr[i], arr[i+1]);
		}
	}
} 

int main(){
	
	int even[7] = {5,7,3,9,10,12,8};
	int odd[5] = {-10,2,1,8,5,};
	
	swapAlternate(even , 7);
	printArray(odd , 5);
	
	cout<<endl;
	
	swapAlternate(odd, 5);
	printArray(even, 7);


}
