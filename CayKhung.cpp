#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<pair<int, int>> &T){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            T.push_back({u, v});
            dfs(v, adj, visited, T);
        }
    }
}

void bfs(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<pair<int, int>> &T){
    queue<int> qu;
    qu.push(u);
    visited[u] = true;
    while (!qu.empty()){
        int s = qu.front();
        qu.pop();
        for (int v : adj[s]){
            if (!visited[v]){
                T.push_back({s, v});
                qu.push(v);
                visited[v] = true;
            }
        }
    }
}

void dothi(int n, vector<vector<int>> &a, vector<vector<int>> &adj){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1 && i < j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

int main(){
    int n, u;
    cin >> n >> u;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<bool> visited(n + 1, false);
    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> T;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    dothi(n, a, adj);
    dfs(u, adj, visited, T);

    cout << "DFS tree\n";
    for (auto i : T){
        if (max(i.first, i.second) == i.first) cout << i.second << " " << i.first << endl;
        else cout << i.first << " " << i.second << endl;
    }

    T.clear();
    visited.assign(n + 1, false);

    bfs(u, adj, visited, T);
    cout << "BFS tree\n";
    for (auto i : T){
        if (max(i.first, i.second) == i.first) cout << i.second << " " << i.first << endl;
        else cout << i.first << " " << i.second << endl;
    }
    return 0;
}