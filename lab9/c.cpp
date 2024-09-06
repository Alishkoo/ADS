#include <bits/stdc++.h>
using namespace std;

vector<int> pref_function(string s)
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
void leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
}
vector<int> kmp(string s, string t)
{
    s = t + '#' + s;
    vector<int> res;
    vector<int> pi = pref_function(s);
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
    string s, t;
    cin >> s >> t;
    int cnt = 0;
    while (s != t && cnt != s.size())
    {
        leftrotate(t, 1);
        cnt++;
    }
    if (cnt < s.size())
        cout << cnt;
    else
        cout << -1;

    return 0;
}