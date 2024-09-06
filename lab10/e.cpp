#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector <vector <int> > graph(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    while(q--) {
        int a, b, c; cin >> a >> b >> c;
        if (graph[a - 1][b - 1] == 1 && graph[a - 1][c - 1] && graph[b - 1][c - 1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}