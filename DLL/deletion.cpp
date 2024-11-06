#include<iostream>
using namespace std;

void insertData(int arr[], int &n, int num, int pos) {
    // Shift elements to the right from the last position to the given position
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the new element at the given position
    arr[pos] = num;
    n++;  // Increase the array size
}

void deleteData(int arr[], int &n, int pos) {
    // Check if the position is valid for deletion
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!" << endl;
        return;
    }
    // Shift elements to the left to delete the element at the given position
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;  // Decrease the size of the array
}


void showArray(int arr[], int n) {  // Changed return type to void
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {1, 3, 5, 7, 9, 11};  // Increased size to allow insertion
    int n = 6;  // Current size of the array
    
    cout << "The array elements are: " << endl;
    showArray(arr, n);  // Call showArray function to display elements
    
    int num, pos;
    cout << "Enter the element you want to add: ";
    cin >> num;
    cout << "Enter the position where you want to insert the element (0-based index): ";
    cin >> pos;

    if (pos >= 0 && pos <= n) {  // Check if the position is valid
        insertData(arr, n, num, pos);  // Insert the new element
        cout << "Array after insertion: " << endl;
        showArray(arr, n);  // Display the array after insertion
    } else {
        cout << "Invalid position!" << endl;
    }
    
    cout<<"Enter the element you want to delete "<<endl;
    cin>>pos;
    
    deleteData(arr , n , pos);
    cout<<"Array after deletion ";
    showArray(arr , n);
    
    return 0;
}

