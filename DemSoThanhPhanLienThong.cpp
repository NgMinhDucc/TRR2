#include <bits/stdc++.h>
using namespace std;

void bfs(int u, vector<bool> &visited, vector<vector<int>> &adj){
    queue<int> qu;
    qu.push(u);
    visited[u] = true;
    while (!qu.empty()){
        int s = qu.front();
        qu.pop();
        for (int v : adj[s]){
            if (!visited[v]){
                qu.push(v);
                visited[v] = true;
            }
        }
    }
}

int thanh_phan_lien_thong(int n, vector<bool> &visited, vector<vector<int>> &adj){
    int tplt = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            tplt += 1;
            bfs(i, visited, adj);
        }
    }
    return tplt;
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
    cout << thanh_phan_lien_thong(n, visited, adj);
    return 0;
}