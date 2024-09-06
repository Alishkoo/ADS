#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector <int> &a, size_t start, size_t end){
    if(end - start < 2){
        return;
    }
    if(end - start == 2){
        if(a[start] > a[start + 1]){
            swap(a[start], a[start + 1]);
        }
    }

    mergeSort(a, start, start + (end - start) / 2);
    mergeSort(a, start + (end - start) / 2, end);

    vector <int> b;
    
}

int main(){
    vector <int> v;

    for(int i = 0; i < 20; i++){
        v.push_back(i);
    }

    for(int i = 0; i < v.size(); i++){
        swap(v[i], v[rand() % (v.size() - i) + i]);
    }

    mergeSort(v, 0, v.size() - 1);

    for(auto i : v){
        cout << i << " ";
    }
}