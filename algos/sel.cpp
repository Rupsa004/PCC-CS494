#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " integers separated by spaces:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "\nOriginal array:\n";
    printArray(arr, n);
    selectionSort(arr, n);
    cout << "\nSorted array (using Selection Sort):\n";
    printArray(arr, n);

    return 0;
}