#include <iostream>
#include <vector>
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
    vector<int> res;
    vector<int> pi = prefixFunction(s);
    for (int i = 0; i < s.size(); i++)
    {
        if (pi[i] == t.size())
        {
            res.push_back(i - 2 * t.size());
        }
    }
    return res;
}

vector<string> checkSuffixOfPrefix(vector<string> input_of_towns, string s, int n)
{
    vector<pair<string, int>> to_check;
    vector<string> answer;
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        vector<int> pi = prefixFunction(input_of_towns[i] + "#" + s);
        if (pi[pi.size() - 1] > maxi)
        {
            maxi = pi[pi.size() - 1];
            to_check.clear();
            to_check.push_back({input_of_towns[i], pi[pi.size() - 1]});
        }
        else if (pi[pi.size() - 1] == maxi)
            to_check.push_back({input_of_towns[i], pi[pi.size() - 1]});
    }
    for (auto i : to_check)
    {
        if (i.second == maxi)
        {
            answer.push_back(i.first);
        }
    }
    return answer;
}
int main()
{
    string to_check;
    vector<string> input_of_towns, answer;
    cin >> to_check;
    int n;
    cin >> n;
    to_check[0] = tolower(to_check[0]);
    for (int i = 0; i < n; i++)
    {
        string towns;
        cin >> towns;
        towns[0] = tolower(towns[0]);
        input_of_towns.push_back(towns);
    }
    answer = checkSuffixOfPrefix(input_of_towns, to_check, n);
    cout << answer.size() << endl;

    for (int i = 0; i < answer.size(); i++)
    {
        answer[i][0] = toupper(answer[i][0]);
        cout << answer[i] << endl;
    }

    return 0;
}