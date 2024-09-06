#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        // Flag to optimize by checking if any swaps were made during this pass
        bool swapped = false;

        // Loop through the unsorted portion of the array
        for (int j = 0; j < n - 1 - i; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swaps were made in this pass, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

void fight_club(vector <int> &arr, int p, int n){
    long long cnt = 0, sum = 0;
    for(int i = 0; i < n; i++){
        if(p >= arr[i]){
            cnt++;
            sum += arr[i];
        } 
        else break;
    }

    cout << cnt << " " << sum << endl;
}

int main(){
    int n;
    cin >> n;
    vector <int> v;
    for(int i = 0; i < n; ++i){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    bubbleSort(v, n);

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int p;
        cin >> p;
        fight_club(v, p, n);
    }

}