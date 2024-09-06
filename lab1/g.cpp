#include <iostream>

using namespace std;

int main(){
    int k;

    const int num = 10000;
    int arr[num] = {0};
    int prime[num] = {0};
    cin >> k;

    for(int i = 2; i * i < num; i++){
        if(arr[i] == 0) {
            for(int j = i * i; j < num; j += i){
                arr[j] = 1;
            }
        }
    }

    int cnt = 0;
    for(int i = 2; i < num; i++){
        if (arr[i] == 0){
            prime[cnt] = i;
            cnt++;
        }
    }
    int cnt1 = 1;
    for (int i = 2; i < cnt; i++){
        if (arr[i] == 0){
            arr[cnt1] = prime[i - 1];
            cnt1++;
        }
    }

    cout << arr[k] << endl;

    return 0;
}