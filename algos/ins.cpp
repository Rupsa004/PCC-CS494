#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;
    int arr[N];
    cout << "Enter " << N << " integers separated by spaces:\n";
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << "\nOriginal array:\n";
    printArray(arr, N);
    insertionSort(arr, N);
    cout << "\nSorted array:\n";
    printArray(arr, N);
    
    return 0;
}