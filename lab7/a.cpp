#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string, int> v1, pair<string, int> v2)
{
    if (v1.second < v2.second)
    {
        return true;
    }
    else if (v1.second == v2.second)
        return true;
    return false;
}

vector<pair<string, int>> merge(vector<pair<string, int>> &a, vector<pair<string, int>> &b)
{
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    vector<pair<string, int>> c;
    while (i < n && j < m)
    {
        if (comp(a[i], b[j]))
        {
            c.push_back(a[i]);
            i++;
        }
        else
        {
            c.push_back(b[j]);
            j++;
        }
    }
    while (i < n)
    {
        c.push_back(a[i]);
        i++;
    }
    while (j < m)
    {
        c.push_back(b[j]);
        j++;
    }

    return c;
}

vector<pair<string, int>> merge_sort(vector<pair<string, int>> &a)
{
    if (a.size() == 1)
        return a;
    vector<pair<string, int>> al, ar;
    int n = a.size();
    for (int i = 0; i < n / 2; i++)
    {
        al.push_back(a[i]);
    }
    for (int i = n / 2; i < n; i++)
    {
        ar.push_back(a[i]);
    }
    al = merge_sort(al);
    ar = merge_sort(ar);
    return merge(al, ar);
}

vector<pair<string, int>> getVector(vector<pair<string, int>> &a, string s, string start_str)
{
    for (int j = 0; j < s.size(); j++)
    {
        if (s[j] != ' ')
        {
            start_str += s[j];
        }
        else
        {
            a.push_back({start_str, start_str.size()});
            start_str = "";
        }
    }
    a.push_back({start_str, start_str.size()});
    return a;
}

int main()
{
    string start_str = "";
    string n;
    getline(cin, n);
    int new_n = stoi(n);
    string s;
    vector<pair<string, int>> a;
    for (int i = 0; i < new_n; i++)
    {
        getline(cin, s);
        getVector(a, s, start_str);
        a = merge_sort(a);
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i].first << ' ';
        }
        cout << endl;
        a.clear();
    }
}