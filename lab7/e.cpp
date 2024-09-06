#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &v1, vector<int> &v2)
{
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		sum1 += v1[i];
		sum2 += v2[i];
	}
	if (sum1 == sum2)
	{
		return v1 < v2;
	}
	if (sum1 > sum2)
		return true;

	return false;
}

vector<vector<int>> merge(vector<vector<int>> &arr, vector<vector<int>> &arr1)
{
	int n = arr.size();
	int m = arr1.size();
	int i = 0, j = 0;
	vector<vector<int>> c;
	while (i < n && j < m)
	{
		if (comp(arr[i], arr1[j]))
		{
			c.push_back(arr[i]);
			i++;
		}
		else
		{
			c.push_back(arr1[j]);
			j++;
		}
	}
	while (i < n)
	{
		c.push_back(arr[i]);
		i++;
	}
	while (j < m)
	{
		c.push_back(arr1[j]);
		j++;
	}

	return c;
}

vector<vector<int>> merge_sort(vector<vector<int>> &arr)
{
	if (arr.size() == 1)
		return arr;
	vector<vector<int>> al, ar;
	int n = arr.size();
	for (int i = 0; i < n / 2; i++)
	{
		al.push_back(arr[i]);
	}
	for (int i = n / 2; i < n; i++)
	{
		ar.push_back(arr[i]);
	}
	al = merge_sort(al);
	ar = merge_sort(ar);
	return merge(al, ar);
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v;
	vector<int> tempp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			cin >> x;
			tempp.push_back(x);
		}
		v.push_back(tempp);
		tempp.clear();
	}
	v = merge_sort(v);
	for (auto i : v)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}