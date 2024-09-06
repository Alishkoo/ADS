#include <iostream>
#include <vector>

using namespace std;

void dfs (vector <vector <int> > &grid, int i, int j){
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return;
    if (grid[i][j] == 0)
        return;
    if (grid[i][j] == 1)
        grid[i][j] = 0;
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector <vector <int> > grid(n, vector <int> (m));
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        for (int j = 0; j < m; j++){
            grid[i][j] = s[j] - '0';
        }
    }
    int my_cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1){
                dfs(grid, i, j);
                my_cnt++;
            }
        }
    }
    cout << my_cnt;
}