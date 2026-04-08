#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool> &visited, vector<vector<int>> &adj){
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v, visited, adj);
        }
    }
}

void dothi(int n, vector<vector<int>> &a, vector<vector<int>> &adj){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1 && i < j){
                adj[i].push_back(j);
                adj[j].push_back(i); // bo di neu do thi la do thi co huong
            }
        }
    }
}

int main(){
    int n, u;
    cin >> n >> u;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    dothi(n, a, adj);
    dfs(u, visited, adj);
    return 0;
}