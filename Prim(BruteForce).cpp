#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
};

int n, u;
int a[1001][1001];
vector<pair<int, int>> adj[1001];
vector<bool> visited(1001);

void dothi(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] != 0 && i < j){
                adj[i].push_back({j, a[i][j]});
                adj[j].push_back({i, a[i][j]});
            }
        }
    }
}

void prim(int u){
    vector<edge> mst;
    int d = 0;
    visited[u] = true;
    while ((int)mst.size() < n - 1){
        int min_w = 100000000;
        int x, y;
        for (int i = 1; i <= n; i++){
            if (visited[i]){
                for (pair<int, int> it : adj[i]){
                    int j = it.first, ts = it.second;
                    if (!visited[j] and ts < min_w){
                        min_w = ts;
                        x = j;
                        y = i;
                    }
                }
            }
        }
        mst.push_back({x, y, min_w});
        d += min_w;
        visited[x] = true;
    }
    cout << "dH = " << d << endl;
    for (edge e: mst){
        if (e.u > e.v) cout << e.v << " " << e.u << endl;
        else cout << e.u << " " << e.v << endl;
    }
}

int main(){
    cin >> n  >> u;
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    dothi();
    prim(u);
    return 0;
}