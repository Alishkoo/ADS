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


int main()
{
    string st;
    cin >> st;
    vector<int> pi = prefixFunction(st);
    int l = pi[st.size()-1];
    cout << st.size()-l;
    return 0;
   
}