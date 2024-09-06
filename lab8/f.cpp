#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long MOD = 9007199254740881;
long long X = 31;

int main(){
    string s;
    cin >> s;
    long long cnt = 0;
    unordered_map<unsigned long long, unsigned long long> mp;
    for (int i = 0; i < s.size(); i++)
    {
        long long hash = 0;
        for (int j = i; j < s.size(); j++)
        {
            hash = (hash * 26 + s[j]) % MOD;//rolling hash
            if (mp.find(hash) == mp.end())
            {
                cnt++;
            }
            mp[hash] = 1;
        }
    }
    cout << cnt;

}