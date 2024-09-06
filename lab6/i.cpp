#include <iostream>
using namespace std;

void heapify(string &arr, int sz, int i){
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

void heapSort(string &arr, int sz){
    for(int i = sz / 2 - 1; i >= 0; i--){
        heapify(arr, sz, i);
    }

    for(int i = sz - 1; i >= 0; i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main(){
    string cons;

    cin >> cons;


    heapSort(cons, cons.size());

    cout << cons << endl;
    
}