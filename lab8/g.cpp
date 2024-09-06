#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

const int p = 31;

ull power(int p, int m)
{
    ull result = 1;
    for (int i = 0; i < m; i++)
        result *= p;
    return result;
}

ull my_hash(const string str)
{
    ull h = 0;
    for (char ch : str)
    {
        h = h * p + ch;
    }
    return h;
}

int rabin_karp(string pattern, string text)
{
    int m = pattern.length();
    int n = text.length();
    int count = 0;

    ull hp = my_hash(pattern);
    ull h = my_hash(text.substr(0, m));
    ull pm = power(p, m);

    for (int i = 0; i <= n - m; i++)
    {
        if (hp == h)
        {
            count++;
        }
        if (i < n - m)
        {
            h = h * p + text[i + m] - text[i] * pm;
        }
    }

    return count;
}


int main()
{
    string str;
    cin >> str;

    int n = str.size();

    int input;
    cin >> input;

    int p1, p2;
    for (int i = 0; i < input; i++)
    {
        cin >> p1 >> p2;
        int m = p2 - p1 + 1;
        cout << rabin_karp(str.substr(p1 - 1, m), str) << endl;
    }
}