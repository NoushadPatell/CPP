#include <iostream>

using namespace std;

template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the element at index i
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

template <typename T>
void displayArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int intSize = 5;
    int intArray[intSize] = {42, 13, 7, 91, 29};

    const int floatSize = 4;
    float floatArray[floatSize] = {3.14f, 2.71f, 1.618f, 0.5f};

    // Sorting and displaying integer array
    cout << "Original integer array: ";
    displayArray(intArray, intSize);
    selectionSort(intArray, intSize);
    cout << "Sorted integer array: ";
    displayArray(intArray, intSize);

    // Sorting and displaying float array
    cout << "\nOriginal float array: ";
    displayArray(floatArray, floatSize);
    selectionSort(floatArray, floatSize);
    cout << "Sorted float array: ";
    displayArray(floatArray, floatSize);

    return 0;
}
