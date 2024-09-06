#include <iostream>

using namespace std;

int main(){
    int k;
    const int num = 10000;
    int arr[num] = {0};
    int prime[num];
    cin >> k;

    for(int i = 2; i * i < num; i++){
        if(arr[i] == 0) {
            for(int j = i * i; j < num; j += i){
                arr[j] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 2; i < num; i++){
        if (arr[i] == 0){
            cnt++;
            if (cnt == k){
                cout << i;
                return 0;
            }
        }
    }

    return 0;
}