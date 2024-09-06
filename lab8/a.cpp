#include <bits/stdc++.h>

using namespace std;

string calc_hash(string t){
    long long q = 1e9 + 7;
    long long x = 11;
    long long h = 0;
    long long x_pow = 1;

    for(int i = 0; i < t.size(); i++){
        h =  (h + ((t[i] - 47) * x_pow) % q ) % q;
        x_pow = (x_pow * x) % q;
    }

    return to_string(h);
}

int main(){
    int n;
    cin >> n;

    unordered_map<string, long long> st;
    vector<string> v(2*n);

    for(int i = 0; i < 2*n; i++){
        cin >> v[i];
        st[v[i]] = 1;
    }


    long long cnt = 0;
    for (auto it : v)
    {
        string hash = calc_hash(it);
        if (st.find(hash) != st.end())
        {
            cout << "Hash of string " << '"' << it << '"' << " is " << hash << endl;
            cnt++;
        }
        if (cnt == n)
            return 0;
    }
    return 0;
    
}