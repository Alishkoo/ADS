#include <bits/stdc++.h>

using namespace std;
//define things 

const int p = 31;
const int mode = (int)1e9 + 7;

void mmerge(vector<int> v1, vector<int> v2, int n, int m, int &cnt)
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

int binarySearch(vector<int> arr, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // If we reach here, then element was not present
    return -1;
}

int calc_hash(string s) {
    int h = 0; 

    for(auto i : s){
        h = (h * p + (i - 'a' + 1)) % mode;
    }

    return h;
}

vector<int> search_text(string s, string w){
    vector <int> ans;

    int n = s.size();
    int m = w.size();

    int hw = calc_hash(w);
    int hs = calc_hash(s.substr(0, m));

    //pm should be precalculated to m - 1
    int pm = 1;

    for(int i = 0; i < m - 1; i++){
        pm = pm * p;
    }

    int cnt = 0;
    for(int i = 0; i + m <= n; i++){
        if(hs == hw){
            ans.push_back(i);
        }
        //[i, i + m - 1] --> [i + 1, i + m]

        if(i + m < n){
            hs = (hs - (s[i] - 'a' + 1) * pm) * p + s[i + m] - 'a' + 1;
        }
    }

    return ans;
}

int main(){
    string first, second, prst;

    cin >> first >> second >> prst;

    vector<int> v1 = search_text(first, prst);
    vector<int> v2 = search_text(second, prst);


    int cnt = 0;
    // for(int i = 0; i < v1.size(); i++){
    //     // cout << binarySearch(v2, 0, v2.size() - 1, v1[i]) << endl;
    //     if(binarySearch(v2, 0, v2.size() - 1, v1[i]) >= 0)
    //         cnt++;
    // }

    mmerge(v1, v2, v1.size(), v2.size(), cnt);

    cout << cnt;
}