#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int bfs(vector<vector<int>> &graph, int start, int end){
    start--;
    end--;
    vector<int> dist(graph.size(), INF);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int to = 0; to < graph.size(); to++){
            if(dist[to] > dist[v] + 1 && graph[v][to]){
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    // for(int h = 0; h < dist.size(); h++){
    //     cout << dist[h] << ' ';

    // }
    // cout << endl;

    if(dist[end] == INF){
        return -1;
    }
    return dist[end];


}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int> (n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    int start, end;
    cin >> start >> end;

    cout << bfs(graph, start, end);

}