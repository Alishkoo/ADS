#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

vector<int> bfs(vector<vector<int>> &graph, int start){
    start--;

    vector<int> dist(graph.size(), INF);
    queue <int> q;

    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int v = q.front();

        for(int to : graph[v]){
            if(dist[to] > dist[v] + 1){
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist;
}

int main(){
    int vertCount, edgCount, query;
    cin >> vertCount >> edgCount >> query;


    vector<vector<int>> graph(vertCount);
    vector<int> is_red(vertCount, 0);

    for(int i = 0; i < edgCount; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int k = 0; k < query; k++){
        int n, m;
        cin >> n >> m;

        // ! закрашиваю в красный если нужно
        //! такооой костыыль епт
        if(n == 1){
            is_red[m] = 1;
        }
        else{
            if(is_red[m]){
                cout << 0 << endl;
            }
            else{
                vector<int> dist = bfs(graph, m);
                int temp = INT_MAX;
                for(int j = 0; j < is_red.size(); ++j){
                    if(is_red[j]){
                        temp = min(temp, dist[j]);
                    }
                }
                if(temp == INF) cout << -1 << endl;
                else cout << temp << endl;
            }
        }
    }

}