#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

map<string, double> mp = {
    {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00}, {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00}, {"F", 0}};

bool comp(pair<pair<string, string>, double> v1, pair<pair<string, string>, double> v2)
{
    if (v1.second < v2.second)
        return true;
    if (v1.second > v2.second)
        return false;
    if (v1.second == v2.second)
    {
        if (v1.first.first < v2.first.first)
            return true;
        if (v1.first.first > v2.first.first)
            return false;
        if (v1.first.second < v2.first.second)
            return true;
        if (v1.first.second > v2.first.second)
            return false;
    }

    return false;
}

vector<pair<pair<string, string>, double>> merge(vector<pair<pair<string, string>, double>> &a, vector<pair<pair<string, string>, double>> &b)
{
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    vector<pair<pair<string, string>, double>> c;
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

vector<pair<pair<string, string>, double>> merge_sortt(vector<pair<pair<string, string>, double>> &a)
{
    if (a.size() == 1)
        return a;
    vector<pair<pair<string, string>, double>> al, ar;
    int n = a.size();
    for (int i = 0; i < n / 2; i++)
    {
        al.push_back(a[i]);
    }
    for (int i = n / 2; i < n; i++)
    {
        ar.push_back(a[i]);
    }
    al = merge_sortt(al);
    ar = merge_sortt(ar);
    return merge(al, ar);
}

double Sumgpas(int subj)
{
    string mark;
    int credit;
    double sum_credit = 0;
    double sum_mark = 0;
    for (int i = 0; i < subj; i++)
    {
        cin >> mark >> credit;
        sum_mark += mp[mark] * credit;
        sum_credit += credit;
    }
    return sum_mark / sum_credit;
}

int main()
{
    vector<pair<pair<string, string>, double>> students;
    double sum;
    int n, subj;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string last_name, first_name;
        cin >> last_name >> first_name;
        cin >> subj;
        sum = Sumgpas(subj);
        students.push_back({{last_name, first_name}, sum});
    }
    students = merge_sortt(students);

    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i].first.first << ' ' << students[i].first.second << ' ' << fixed << setprecision(3) << students[i].second << endl;
    }
    return 0;
}