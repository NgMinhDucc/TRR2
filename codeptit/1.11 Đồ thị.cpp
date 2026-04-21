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

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j){
                a[i][j] = 0;
            }
            else{
                a[i][j] = 10000;
            }
        }
    }

    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = a[v][u] = w;
    }

    if (t == 1){
        for (int i = 1; i <= n; i++){
            int deg = 0;
            for (int j = 1; j <= n; j++){
                if (a[i][j] != 0 && a[i][j] != 10000){
                    deg += 1;
                }
            }
            cout << deg << " ";
        }
    }
    else{
        cout << n << endl;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}