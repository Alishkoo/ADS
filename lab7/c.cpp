#include <bits/stdc++.h>
using namespace std;
void merge_duplicat(vector<int> arr, vector<int> arr2)
{
    int i = 0, j = 0;
    while (i < arr.size() && j < arr2.size())
    {
        if (arr[i] > arr2[j])
        {
            j++;
        }
        else if (arr2[j] > arr[i])
        {
            i++;
        }
        else
        {
            // when both are equal
            cout << arr[i] << " ";
            i++;
            j++;
        }
    }
}

vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> result;
    int l = 0, r = 0;
    while (l < left.size() && r < right.size())
    {
        if (left[l] <= right[r])
        {
            result.push_back(left[l]);
            l++;
        }
        else
        {
            result.push_back(right[r]);
            r++;
        }
    }
    while (l < left.size())
    {
        result.push_back(left[l]);
        l++;
    }
    while (r < right.size())
    {
        result.push_back(right[r]);
        r++;
    }
    return result;
}

vector<int> merge_sort(vector<int> a, int l, int r)
{
    if (l == r)
    {
        vector<int> result;
        result.push_back(a[l]);
        return result;
    }
    int m = l + (r - l) / 2;
    vector<int> left = merge_sort(a, l, m);
    vector<int> right = merge_sort(a, m + 1, r);
    return merge(left, right);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), arr2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    if (n != 0 && m != 0)
    {
        arr = merge_sort(arr, 0, n - 1);
        arr2 = merge_sort(arr2, 0, m - 1);
        merge_duplicat(arr, arr2);
    }

    return 0;
}