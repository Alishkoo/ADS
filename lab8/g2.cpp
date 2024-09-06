#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

ull calc_hash(string s) {
    ull h = 0;
    ull p = 31;
    ull p_pow = 1;

    for (int i = 0; i < s.size(); i++) {
        h += (s[i] - 'a') * p_pow;
        p_pow *= 31;
    }
    return h;
}

vector<ull> find_hash(string s) {
    ull n = s.size();
    vector<ull> h(n);
    ull p = 31;
    ull p_pow = 1;
    h[0] = s[0] - 'a';

    for (int i = 1; i < n; i++) {
        p_pow *= 31;
        h[i] = h[i - 1] + (s[i] - 'a') * p_pow;
    }

    return h;
} 

void search(string s, string t) {

    ull hash_t = calc_hash(t);
    vector<ull> hash = find_hash(s);
    ull n = s.size();
    ull m = t.size();
    ull p[n];
    p[0] = 1;

    for (int i = 1; i < n; i++){
        p[i] = p[i - 1] * 31;
    }

    int cnt = 0;
    for (int i = 0; i < n - m + 1; i++) {
        ull j = i + m - 1;
        ull hashij = hash[j];
        if (i > 0)
             hashij -= hash[i - 1];
        if (hashij == hash_t * p[i]) {
            cnt++;
        }
    }

    cout << cnt << endl;
}

int main(){
    string s;
    cin >> s;

    int a,b;
    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        search(s, s.substr(a - 1, (b - a) + 1));
    }

    return 0;
}