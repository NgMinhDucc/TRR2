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

void dinhtru(int n, vector<bool> &visited, vector<vector<int>> &adj){
    int cnt = 0; // so thanh phan lien thong ban dau
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cnt += 1;
            dfs(i, visited, adj);
        }
    }

    for (int i = 1; i <= n; i++){
        int dem = 0;
        visited.assign(n + 1, false);
        visited[i] = true; // loai bo dinh
        for (int j = 1; j <= n; j++){
            if (!visited[j]){
                dem += 1; // so dinh tru sai khi dinh thu i bi loai
                dfs(j, visited, adj);
            }
        }
        if (dem > cnt){
            cout << i << " ";
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
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    dothi(n, a, adj);
    dinhtru(n, visited, adj);
    return 0;
}