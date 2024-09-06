#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(string s)
{
    vector<int> pi(s.size());
    pi[0] = 0;
    for (int i = 1; i < s.size(); i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
        {
            j = pi[j - 1];
        }
        if (s[j] == s[i])
        {
            pi[i] = j + 1;
        }
        else
        {
            pi[i] = 0;
        }
    }

    return pi;
}

vector<int> kmp(string s, string t)
{
    s = t + '#' + s;
    vector<int> res;
    vector<int> pi = prefixFunction(s);
    for (int i = 0; i < s.size(); i++)
    {
        if (pi[i] == t.size())
        {
            res.push_back(i - 2 * t.size());
        }
    }
    return res;
}

int main()
{
    int cnt = 1;
    string s, t;
    cin >> s >> t;
    vector<int> pi;
    string incr_s = s;
    while (s.size() < t.size())
    {
        s += incr_s;
        cnt++;
    }
    if(kmp(s,t).size()!=0){
        cout << cnt;
        return 0;
    }  
    if(kmp(s+incr_s,t).size()!=0){
        cout << cnt+1;
        return 0;
    }
    cout << -1;
}