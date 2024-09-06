#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge{
    int a, b, weight;
};

//! O(V*E) 
//! оружие последнего шанса
vector<int> ford_bellman(vector<Edge> &graph, int start, int vertexCount){
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;

    //TODO
    vector<int> from(graph.size(), -1);


    for(int i = 0; i < graph.size() - 1; i++){
        for(size_t j = 0; j < graph.size(); j++){
            int a = graph[j].a;
            int b = graph[j].b;
            int weight = graph[j].weight;

            if(dist[a] != INF && dist[b] > dist[a] + weight){
                dist[b] = dist[a] + weight;
                //TODO
                from[b] = a;
            }
        }
    }

    return dist;
}

vector<int> getPath(vector<int> &from,int finish){
    vector<int> path;
    for(int v = finish; v =! -1; v = from[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
}

int main(){
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> graph(edgeCount);

    for(int i = 0; i < edgeCount; i++){
        cin >> graph[i].a >> graph[i].b >> graph[i].weight;
    }

    int start;
    cin >> start;

    vector<int> dist = ford_bellman(graph, start, vertexCount);
}