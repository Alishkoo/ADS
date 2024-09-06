#include <iostream>
using namespace std;

void heapifyy(string &arr, int sz, int i){
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < sz && arr[left] > arr[largest])
        largest = left;
    
    if(right < sz && arr[right] > arr[largest])
        largest = right;

    if(i != largest){
        swap(arr[largest], arr[i]);
        heapifyy(arr, sz, largest);
    }
}

void heapSort(string &arr, int sz){
    for(int i = sz / 2 - 1; i >= 0; i--){
        heapifyy(arr, sz, i);
    }

    for(int i = sz - 1; i >= 0; i--){
        swap(arr[i], arr[0]);
        heapifyy(arr, i, 0);
    }
}

int main(){
    string vowels, consonants;

    int sz;
    cin >> sz;
    char t;

    for(int i = 0; i < sz; i++){
        cin >> t;
        if(t == 'a' || t == 'e' || t == 'i' || t == 'u' || t == 'o'){
            vowels += t;
        }
        else {
            consonants += t;
        }
    }


    heapSort(vowels, vowels.size());
    heapSort(consonants, consonants.size());

    cout << vowels << consonants << endl;
    
}