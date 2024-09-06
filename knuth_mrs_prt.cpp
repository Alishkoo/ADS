#include <bits/stdc++.h>

using namespace std;

vector <int> prex_func(string s){
    vector <int> p(s.size());
    p[0] = 0;
    int n = s.size();

    for(int i = 1; i < n; i++){
        int j = p[i - 1];
        while(j > 0 && s[j] != s[i]){
            j = p[j - 1];
        }

        if(s[i] == s[j]) j++;
        p[i] = j;
    }

    return p;
}

int main(){

    

}