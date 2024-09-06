#include <iostream>
#include <vector>

using namespace std;

bool Binarysearch(vector<int> &v, int target){
    int l = 0;
    int r = v.size() - 1;
    int mid = (l + r) / 2;

    while(l <= r){
        mid = l + (r - l) / 2;

        if(v[mid] == target){
            return 1;
        }
        else if (v[mid] > target){
            r = mid - 1;
        }
        else if(v[mid] < target){
            l = mid + 1;
        }
    }
    return 0;
}

int main(){
    int n, target;
    cin >> n;

    vector<int> v;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    cin >> target;

    if(Binarysearch(v, target)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}