#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define N 100000

vector <int> degr(N, 0);
vector <int> org_degrt(N, 0);
queue <int> quests;

bool topsort (vector <vector <int> > &adj, int n){
    queue <int> q;
    for (int i = 0; i < n; i++){
        if (degr[i] == 0){
            q.push(i);
            quests.push(i);
        }
    }
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        n--;
        for (int i = 0; i < adj[cur].size(); i++){
            if (--degr[adj[cur][i]] == 0){
                q.push(adj[cur][i]);
                quests.push(adj[cur][i]);
            }
        }
    }
    return n == 0;
}

int main() {
    int n, m; 
    cin >> n >> m;
    vector <vector <int> > adj(n);
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        degr[b - 1]++;
        org_degrt[b - 1]++;
    }
    for (int i = 0; i < n; i++) {
        if (!org_degrt[i])
            continue;
        for (int j = 0; j < n; j++)
            degr[j] = org_degrt[j];
        --degr[i];
        if (topsort(adj, n)) {
            cout << "YES";
            return 0;
        }
    }
   cout << "NO";
}