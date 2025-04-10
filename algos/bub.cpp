#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {
    for (int step = 0; step < size - 1; ++step) {
        int swapped = 0;
        for (int i = 0; i < size - step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    
    int data[size];
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        cin >> data[i];
    }
    cout << "\nUnsorted Array:\n";
    printArray(data, size);
    bubbleSort(data, size);
    cout << "\nSorted Array in Ascending Order:\n";
    printArray(data, size);
    
    return 0;
}