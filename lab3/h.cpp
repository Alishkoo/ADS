#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i != 0){
            arr[i] += arr[i - 1];
        }
    }

    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        int left = 0; 
        int right = n - 1;

        while(left < right){
            int mid = left + (right - left) / 2;
            if(t > arr[mid]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        cout << left + 1<< endl;
    }
}