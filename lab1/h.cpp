#include <iostream>

using namespace std;

bool isprime(int k){
    for(int i = 2; i < k; i++){
        if(k % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int k;
    cin >> k;

    if (isprime(k) && k != 1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}