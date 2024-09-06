#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector< vector<int>> dist(vertexCount, vector<int> (vertexCount, INF));

    //! FLOYD REALIZATION
    for(int v = 0; v < vertexCount; v++){
        for(int a = 0; a < vertexCount; a++){
            for(int b = 0; b < vertexCount; b++){
                if(dist[a][v] != INF && dist[v][b] != INF &&
                    dist[a][b] > dist[a][v] + dist[v][b]){
                        dist[a][b] = dist[a][v] + dist[v][b];

                    }
            }
        }
    }
}