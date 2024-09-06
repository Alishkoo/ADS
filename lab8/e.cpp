#include <iostream>
#include <vector>

using namespace std;

string calc_hash(vector<long long> v){
    int n = v.size();
    int p = 2;
    long long p_pow = 1;
    long long h = 0;
    string t = "";

    char ch;
    ch = char(v[0] + 97);
    t += ch;
    p_pow *= 2;

    for(int i = 0; i < n - 1; i++){
        t += char(((v[i + 1] - v[i]) / p_pow) + 97);
        p_pow *= 2;
    }

    return t;
}

int main(){
    int n; 
    cin >> n;
    vector <long long> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << calc_hash(v) << endl;
}