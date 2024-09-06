#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

//! O(V + E) if adjency list
//! O(V^^2) if adjency matrix
//TODO отмечу оранжевым как помечать сам кратчайший путь
vector<int> bfs_list(vector<vector<int>> &graph, int start){
    vector<int> visited(graph.size());
    vector<int> dist(graph.size(), INF);
    queue<int> q;
    //TODO создаем вектор для хранения откуда пришли к этому
    vector<int> from(graph.size(), -1);

    //! можно обойтись и без массива visited
    //! потому что можем использовать dist для того чтобы понимать, мы были там или нет
    //! если она будет посещена значит там значение не INF, а какое то число
    visited[start] = 1;
    dist[start] = 0;
    q.push(start);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        //! with visited
        for(int to : graph[v]){
            if(!visited[to]){
                visited[to] = 1;
                dist[to] = dist[v] + 1;
                q.push(to);
                //TODO 
                from[to] = v;
                
            }
        }

        //! without
         for(int to : graph[v]){
            if(dist[to] > dist[v] + 1){
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist;
}

//TODO вычисление самого пути
vector<int> getPath(vector<int> &from, int finish){
    vector<int> path;
    for(int v = finish; v != -1; v = from[v]){
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    return path;
}

vector<int> bfs_matrix(vector<vector<int>> &graph, int start){
    vector<int> visited(graph.size());
    vector<int> dist(graph.size(), INF);
    queue<int> q;

    //! можно обойтись и без массива visited
    //! потому что можем использовать dist для того чтобы понимать, мы были там или нет
    //! если она будет посещена значит там значение не INF, а какое то число
    visited[start] = 1;
    dist[start] = 0;
    q.push(start);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int to = 0; to < graph.size(); to++){
            //! еще примечание dist[to] > dist[v] + 1 the same with dist[to] == INF
            if(graph[v][to] && dist[to] == INF){
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist;
}

int main(){

}