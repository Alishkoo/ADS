#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
int p = 31;
#define MAX 1e4
vector<int> p_pow(MAX);

void FillPowers(void)
{
    p_pow[0] = 1;
    for (int i = 1; i < p_pow.size(); i++)
        p_pow[i] = p_pow[i - 1] * p;
}

vector<int> getPrefixHashes(string s)
{
    int n = s.size();
    vector<int> hashes(n + 1);
    int curX = 1;
    for (int i = 1; i <= n; i++)
    {
        hashes[i] = hashes[i - 1] + (s[i - 1] - 'a' + 1) * p_pow[i - 1];
    }
    return hashes;
}

vector<vector<int>> getSubstrFromLeftToMid(vector<vector<int>> &v, int mid, vector<string> strings, vector<vector<int>> hashes_of_strings)
{
    for (int i = 0; i < strings.size(); i++)
    {
        int sz = strings[i].size();
        for (int j = 0; j <= sz - mid; j++)
        {
            int hash =
                (hashes_of_strings[i][j + mid] - hashes_of_strings[i][j]) * p_pow[(5005 - j)];
            v[i].push_back(hash);
        }
    }
    return v;
}

string getSubstr(int left, int right, string orig)
{
    string checked = "";
    for (int i = left; i <= right; i++)
    {
        checked += orig[i];
    }
    return checked;
}
int main()
{
    int n;
    cin >> n;
    string ans = "";
    vector<string> strings(n);
    vector<vector<int>> hashes_of_strings(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strings[i];
    }
    
    FillPowers();

    for (int i = 0; i < n; i++)
    {
        hashes_of_strings[i] = getPrefixHashes(strings[i]);
    }

    int left_orig = 1, right_orig = strings[0].size();

    while (left_orig < right_orig)
    {
        bool check = false;
        int mid_orig = (left_orig + right_orig + 1) / 2;
        vector<vector<int>> hash_of_strings(n);

        hash_of_strings = getSubstrFromLeftToMid(hash_of_strings, mid_orig, strings, hashes_of_strings);

        for (int i = 1; i < n; i++)
        {
            sort(hash_of_strings[i].begin(), hash_of_strings[i].end());
        }
        for (int i = 0; i < hash_of_strings[0].size(); i++)
        {
            int target = hash_of_strings[0][i];
            bool found = true;
            for (int j = 1; j < n; j++)
            {
                if (!binary_search(hash_of_strings[j].begin(), hash_of_strings[j].end(), target))
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                check = true;
                ans = strings[0].substr(i, mid_orig);
                break;
            }
        }
        if (check)
            left_orig = mid_orig;
        else
            right_orig = mid_orig - 1;
    }
    cout << ans;
}