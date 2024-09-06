#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (!st.empty() && st.top() == s[i])
        {
            st.pop();
        }
        else
            st.push(s[i]);
    }

    string ans = st.empty() ? "YES" : "NO";
    cout << ans;
    return 0;
}