#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(string st)
{
    vector<int> pi(st.size());
    pi[0] = 0;
    for (int i = 1; i < st.size(); i++)
    {
        int j = pi[i - 1];
        while (j > 0 && st[j] != st[i])
        {
            j = pi[j - 1];
        }
        if (st[j] == st[i])
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

vector<int> kmp(string st, string t)
{
    st = t + '#' + st;
    vector<int> res;
    vector<int> pi = prefixFunction(st);
    for (int i = 0; i < st.size(); i++)
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
    int n;
    cin >> n;
    while (n--)
    {
        string st;
        int m;
        cin >> st >> m;
        vector<int> pi = prefixFunction(st);
        int k = st.size() - pi.back();
        cout << k * (m - 1) + st.size() << endl;
    }
    return 0;
}