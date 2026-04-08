#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool> &visited, vector<int> &parent, vector<vector<int>> &adj){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            parent[v] = u;
            dfs(v, visited, parent, adj);
        }
    }
}

void path(int s, int e, vector<bool> &visited, vector<int> &parent, vector<vector<int>> &adj){
    dfs(s, visited, parent, adj);
    if (!visited[e]){
        cout << "no path";
    }
    else{
        cout << "DFS path: ";
        while (s != e){
            cout << e << " ";
            e = parent[e];
        }
        cout << s << " ";
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
    int n, s, e;
    cin >> n >> s >> e;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    dothi(n, a, adj);
    path(s, e, visited, parent, adj);
    return 0;
}