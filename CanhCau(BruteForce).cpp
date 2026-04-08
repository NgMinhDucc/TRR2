#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool> &visited, vector<vector<int>> &adj){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v, visited, adj);
        }
    }
}

void bocanh(int u, int s, int t, vector<bool> &visited, vector<vector<int>> &adj){
    visited[u] = true;
    for (int v : adj[u]){
        if ((u == s && v == t) || (u == t && v == s)){
            continue; // loai bo canh (s, t)
        }
        if (!visited[v]){
            bocanh(v, s, t, visited, adj);
        }
    }
}

void canhcau(int n, vector<bool> &visited, vector<vector<int>> &adj, vector<pair<int, int>> &dscanh){
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cnt += 1; // so thanh phan lien thong ban dau
            dfs(i, visited, adj);
        }
    }

    for (auto it : dscanh){
        int x = it.first, y = it.second;
        int dem = 0;
        visited.assign(n + 1, false);
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                dem += 1; // so thanh phan lien thong sau khi bo canh (x, y)
                bocanh(i, x, y, visited, adj);
            }
        }
        if (dem > cnt){
            cout << x << " " << y << endl;
        }
    }
}

void dothi(int n, vector<vector<int>> &a, vector<vector<int>> &adj, vector<pair<int, int>> &dscanh){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1 && i < j){
                adj[i].push_back(j);
                adj[j].push_back(i);
                dscanh.push_back({i, j});
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    vector<pair<int, int>> dscanh;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    dothi(n, a, adj, dscanh);
    canhcau(n, visited, adj, dscanh);
    return 0;
}