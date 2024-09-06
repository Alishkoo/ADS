#include <bits/stdc++.h>
using namespace std;

void topological_sort(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &order){
    visited[v] = 1;

    for(int to : graph[v]){
        if(!visited[to]){
            topological_sort(graph, to, visited, order);
        }
    }

    //! REVERSE AT THE END THIS ORDER
    order.push_back(v);
}

int main(){
    int VertexCount, edgeCount;
    cin >> VertexCount >> edgeCount;

    vector<vector<int>> graph(VertexCount);
    vector<int> order(VertexCount);

    for(int i = 0; i < edgeCount; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(VertexCount);

    //! call dfs.
    //!REVERSEEEE THE ORDER
    reverse(order.begin(), order.end());
}