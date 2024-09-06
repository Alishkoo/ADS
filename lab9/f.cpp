#include <iostream>
#include <vector>
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
    string st, t;
    cin >> st >> t;
    vector<int> res = kmp(st, t);
    cout << res.size() << ' ';
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] + 1 << " ";
    }
    cout << endl;
}