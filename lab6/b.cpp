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

int main(){
    int n, m;
    cin >> n >> m;

    int arrr[n];
    int arr2[m];

    for(int i = 0; i < n; i++){
        cin >> arrr[i];
    }

    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }

    heapSort(arrr, n);
    heapSort(arr2, m);

    int i = 0, j = 0;

    while(i < n && j < m){
        if(arrr[i] == arr2[j]){
            cout << arrr[i] << " ";
            i++;
            j++;
        }

        if(arrr[i] < arr2[j]){
            i++;
        }
        else if(arrr[i] > arr2[j]){
            j++;
        }
    }
}