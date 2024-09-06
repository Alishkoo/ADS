#include <iostream>
using namespace std;

void heapify(int arr[], int sz, int i){
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < sz && arr[left] > arr[largest])
        largest = left;
    
    if(right < sz && arr[right] > arr[largest])
        largest = right;

    if(i != largest){
        swap(arr[largest], arr[i]);
        heapify(arr, sz, largest);
    }
}

void heapSort(int arr[], int sz){
    for(int i = sz / 2 - 1; i >= 0; i--){
        heapify(arr, sz, i);
    }

    for(int i = sz - 1; i >= 0; i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}



void printArray(int arr[], int sz)
{
    for (int i = 0; i < sz; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {15, 12 ,7, 9, 8, 5, 6, 2 };
    int sz = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, sz);

    printArray(arr, sz);

    return 0;
}