#include <bits/stdc++.h>
using namespace std;

void heapify(long long arr[], int sz, int i){
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

void heapSort(long long arr[], int sz){
    for(int i = sz / 2 - 1; i >= 0; i--){
        heapify(arr, sz, i);
    }

    for(int i = sz - 1; i >= 0; i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main(){
    int n;
    cin >> n;
    long long arr[n];

    

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    heapSort(arr, n);

    long long difference = INT_MAX;
    for(int i = 0; i < n - 1; i++){
        if(difference > abs(arr[i] - arr[i + 1])){
            difference = abs(arr[i] - arr[i + 1]);
        }
    }

    for(int i = 0; i < n - 1; i++){
        if(difference == abs(arr[i] - arr[i + 1])){
            cout << arr[i] << " " << arr[i + 1] << " ";
        }
    }

}