#include <bits/stdc++.h>

using namespace std;

//!  O(V+ E) if we using adjency list
void dfs_list(vector<vector<int>> &graph, int v, vector<int> &visited){
    visited[v] = 1;

    for(int to : graph[v]){
        if(!visited[to]){
            dfs_list(graph, to, visited);
        }
    }
}

//! O(V^^2) if we using adjency matrix
void dfs_matrix(vector<vector<int>> &graph, int v, vector<int> &visited){
    visited[v] = 1;

    for(int to = 0; to < graph.size(); to++){
        if(graph[v][to] && !visited[to]){
            dfs_matrix(graph, v, visited);
        }
    }
}

int main(){
    int VertexCount, edgeCount;
    cin >> VertexCount >> edgeCount;

    vector<vector<int>> graph(VertexCount);


    for(int i = 0; i < edgeCount; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(VertexCount);

    // ! componentCount

    int componentCount = 0;

    for(int v = 0; v < VertexCount; v++){
        if(!visited[v]){
            componentCount++;
            // ! call dfs
            dfs_list(graph, v, visited);
        }
    }

    //! call dfs.
}