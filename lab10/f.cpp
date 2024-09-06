#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;



bool bfs (vector <vector <int> > &adj, vector <bool> &visited, int s, int f) {
    queue <int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if (f == u)
            return true;
        for (int i = 0; i < adj[u].size(); i++) {
            if (!visited[adj[u][i]]) {
                visited[adj[u][i]] = true;
                q.push(adj[u][i]);
                if (f == adj[u][i])
                    return true;
            }
        }
    }
    return false;
}

bool solve (vector<vector <int> > &adj, vector <bool> &visited, int s, int f) {
    return bfs(adj, visited, s, f);
}

int main() {
    int n, max;
    cin >> n >> max;
    vector <vector <int> > adj (n);
    vector <bool> visited (n, false);
    while(max--) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    int s, f; cin >> s >> f;
    if (solve(adj, visited, s - 1, f - 1))
        cout << "YES";
    else
        cout << "NO";
}