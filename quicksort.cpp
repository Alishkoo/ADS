#include <bits/stdc++.h>

using namespace std; 

int partition(int arr[], int low, int high){
    int pivot = high;
    int i = low - 1;

    for(int j = low; j <= high; j++){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[pivot]);
    return i + 1;

}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int arr[]={10,7,8,9,1,5};
    int size = 6;

    quickSort(arr, 0, size - 1);
    
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

   
}