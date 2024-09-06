#include <iostream>
#include <vector>
using namespace std;

long long MOD = 1e9 + 7;
long long X = 31;

void merge(vector<int> v1, vector<int> v2, int n, int m, int &cnt)
{
    int i = 0;
    int j = 0;
    while (i != n && j != m)
    {
        if (v1[i] > v2[j])
        {
            j++;
        }
        else if (v1[i] < v2[j])
        {
            i++;
        }
        else
        {
            cnt++;
            i++;
            j++;
        }
    }
}

long long getHash(string s)
{
    long long hash = 0;
    long long curX = 1;
    for (int i = 0; i < s.size(); i++)
    {
        long long curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

vector<long long> getPrefixHashes(string s)
{
    vector<long long> hashes(s.size());
    long long curX = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0)
        {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
}

vector<int> rabinKarp(string s, string t)
{
    long long smallHash = getHash(t);
    vector<int> res;
    vector<long long> hashes = getPrefixHashes(s);
    for (int i = 0; i < s.size() - t.size() + 1; i++)
    {
        long long hashDif = hashes[i + t.size() - 1];
        if (i != 0)
            hashDif -= hashes[i - 1];
        if (hashDif < 0)
            hashDif += MOD;
        if (i != 0)
            smallHash = (smallHash * X) % MOD;
        if (smallHash == hashDif)
        {
            res.push_back(i);
        };
    }
    return res;
}

int main()
{
    string student1, student2, check;

    cin >> student1 >> student2 >> check;

    vector<int> res_student1 = rabinKarp(student1, check);

    vector<int> res_student2 = rabinKarp(student2, check);
    
    int cnt = 0;
    merge(res_student1, res_student2, res_student1.size(), res_student2.size(), cnt);
    cout << cnt;
}