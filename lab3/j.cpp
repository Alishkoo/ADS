#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long arr[],long long n ,long long k, long long h){
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        // while(arr[i]){
        //     if(arr[i] < k){
        //         cnt++;
        //         break;
        //     }
        //     arr[i] -= k;
        //     cnt++;
        // }
        cnt += (arr[i] + k - 1) / k;
    }

    return cnt <= h;
}

int binarysearch(long long arr[], long long n, long long h, long long max){
    long long left = 1, right = max, mid, result = -1;

    while(left <= right){
        mid = left + (right - left) / 2;
        if(isPossible(arr, n, mid , h)){
            result = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    return result;
}

int main(){
    long long n, h, max = INT_MIN;
    cin >> n >> h;

    long long bags[n];

    for(int i = 0; i < n; i++){
        cin >> bags[i];
        if(bags[i] >= max) max = bags[i];
    }
    cout << binarysearch(bags, n, h, max) << endl;

}