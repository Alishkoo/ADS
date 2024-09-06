#include <iostream>
using namespace std;

int super_binary(int arr[], int len, int target){
    int min_len = len + 1;
    for(int i = 0; i < len; i++){
        int left = i, right = len, mid;
        while(left < right){
            mid  = left + (right - left) / 2;
            
            if(arr[mid] - (i > 0 ? arr[i - 1] : 0) < target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }

        if(left >= len){
                break;
            }
            else{
                int cur_min = left - i + 1;
                if(min_len > cur_min){
                    min_len = cur_min;
                }
            }

    }

    return min_len;
}

int main(){
    int len, target;
    cin >> len >> target;
    
    int pref_sum[len];
    for(int i = 0; i < len; i++){
        cin >> pref_sum[i];
        if(i != 0){
            pref_sum[i] += pref_sum[i - 1];
        }
    }

    cout << super_binary(pref_sum, len, target) << endl;
}