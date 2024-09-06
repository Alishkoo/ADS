//! НЕ ИСПОЛЬЗУЕТСЯ ДЛЯ ОТРИЦАТЕЛЬНЫХ ВЕСОВ ГРАНЕЙ
//?-----------------------------------------------
//! Смотри..
//! Если с помощью массива: O(V^^2 + E)
//! Если с помощью сета: O((V+E)log V)
//? реализация такая запарная..

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

//* тоже можно использовать вместо пар интов
struct Edge{
    int to, weight;
};

vector<int> dijkstra(vector<vector<pair<int,int> >> &graph, int start){
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;
    //TODO вычисление того самого короткого пути
    vector<int> from(graph.size(), -1);

    vector<int> visited(graph.size());

    // столько итераций сколько вершин
    for(int i = 0; i < graph.size(); i++){
        int nearest = -1;
        for(int v = 0; v < graph.size(); v++){
           if(!visited[v] && (nearest == -1 || dist[nearest] > dist[v])){
                nearest = v;
            }
        }

        // if(dist[nearest] == INF)
        //     break;

        visited[nearest] = 1;

        for(size_t j = 0; j < graph[nearest].size(); j++){
            int to = graph[nearest][j].first;
            int weight = graph[nearest][j].second;
            if (dist[to] > dist[nearest] + weight){
                dist[to] = dist[nearest] + weight;
                //TODO 
                from[to] = nearest;
            }
        }
    }

    return dist;
}

//TODO 
vector<int> getPath(vector<int> &from, int finish){
    vector<int> path;

    for(int v = from[finish]; v != -1; v = from[v]){
        path.push_back(v);
    }

    reverse(path.begin(), path.end());
}

int main(){
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector< pair<int,int> >> graph(vertexCount);
    for(int i = 0; i < edgeCount; i++){
        int a, b, weight;
        cin >> a >> b >> weight;
        // a--
        // b--

        graph[a].push_back({b, weight});
        graph[b].push_back({a,weight});
    }

    int start;
    cin >> start;

    vector<int> dist = dijkstra(graph, start);

    for(int d : dist){
        if (d !=  INF) cout << d << " ";
        else cout << "X ";
    }
}