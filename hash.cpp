#include <bits/stdc++.h>

using namespace std;
//define things 

const int p = 31;
const int mode = (int)1e9 + 7;

int calc_hash(string s) {
    int h = 0; 

    for(int i = 0; i < s.size(); i++){
        h = (h * p + (s[i] - 'a' + 1)) % mode;
    }

    return h;
}

void search_text(string s, string w){
    // ab
    // ababa
    int n = s.size();
    int m = w.size();

    int hw = calc_hash(w);
    int hs = calc_hash(s.substr(0, m));

    //pm should be precalculated to m - 1
    int pm = 1;

    for(int i = 0; i < m - 1; i++){
        pm = pm * p;
    }

    for(int i = 0; i + m <= n; i++){
        if(hs == hw){
            cout << i << endl;
        }
        //[i, i + m - 1] --> [i + 1, i + m]

        if(i + m < n){
            hs = (hs - (s[i] - 'a' + 1) * pm) * p + s[i + m] - 'a' + 1;
        }
    }
}



int main() {
    string a = "abacaba";
    string b = "ba";
    search_text(a, b);


    return 0;
}