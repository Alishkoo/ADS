#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> v1, vector<int> v2) {
	vector<int> result;
	int left = 0, right = 0;
	while (left < v1.size() && right < v2.size()) {
		if (v1[left] <= v2[right]) {
			result.push_back(v1[left]);
			left++;
		} else {
			result.push_back(v2[right]);
			right++;
		}
	}
	while (left < v1.size()) {
		result.push_back(v1[left]);
		left++;
	}
	while (right < v2.size()) {
		result.push_back(v2[right]);
		right++;
	}
	return result;
}


int main(){
    int n; cin >> n;
    vector<int> v1(n);
    for(int i = 0 ; i < n;i++){
        cin >> v1[i];
    }
    int m; cin >> m;
    vector<int> v2(m);
    for(int i = 0 ; i < m;i++){
        cin >> v2[i];
    }
    vector<int> answer = merge(v1,v2);
    for(auto i : answer){
        cout << i << ' ';
    }
     return 0;
}