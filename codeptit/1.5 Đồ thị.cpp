#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m;
    cin >> t >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    vector<int> degree(n + 1);
    vector<vector<int>> dsk(n + 1);

    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }

    for (int i = 1; i <= n; i++){
        int deg = 0;
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1){
                deg += 1;
                if (i < j){
                    dsk[i].push_back(j);
                    dsk[j].push_back(i);
                }
            }
        }
        degree[i] = deg;
    }

    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << degree[i] << " ";
        }
    }
    else{
        cout << n << endl;
        for (int i = 1; i <= n; i++){
            cout << degree[i] << " ";
            for (int j : dsk[i]){
                cout << j << " ";
            }
            cout << endl;
        }
    }
    return 0;
}