#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool> &visited, vector<int> &path, vector<vector<int>> &adj){
    visited[u] = true;
    path.push_back(u);
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v, visited, path, adj);
        }
    }
}

string check(int n, vector<bool> &visited, vector<int> &path, vector<vector<int>> &adj){
    for (int i = 1; i <= n; i++){
        visited.assign(n + 1, false);
        path.clear();
        dfs(i, visited, path, adj);
        if ((int)path.size() != n){ // tu 1 dinh phai di tham tat ca cac dinh con lai
            return "not strongly connected";
        }
    }
    return "strongly connected";
}

void dothi(int n, vector<vector<int>> &a, vector<vector<int>> &adj){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1);
    vector<int> path;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    dothi(n, a, adj);
    cout << check(n, visited, path, adj);
    return 0;
}