#include <bits/stdc++.h>

using namespace std;

void Binarysearch(int arr[], int left, int right){
    if(left <= right){
        int mid = left + (right - left) / 2;
        cout << arr[mid] << ' ';
        Binarysearch(arr, mid + 1, right);
        Binarysearch(arr, left, mid - 1);
    }
}

int main(){
    int n;
    cin >> n;

    int size = pow(2, n) - 1;

    int arr[size];

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    sort(arr, arr + size);

    Binarysearch(arr, 0, size - 1);
}

