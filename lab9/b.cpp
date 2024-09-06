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
    vector<int> result;
    vector<int> pi = prefixFunction(s);
    for (int i = 0; i < s.size(); i++)
    {
        if (pi[i] == t.size())
        {
            result.push_back(i - 2 * t.size());
        }
    }
    return result;
}

int main()
{
    int k;
    string s, t;
    cin >> s >> k >> t;
    vector<int> result = kmp(t, s);
    if (k <= result.size())
        cout << "YES";
    else
        cout << "NO";
}