#include <bits/stdc++.h>
using namespace std;

int n, u;
vector<vector<int>> a;
vector<bool> visited;
vector<int> path;
vector<vector<int>> allpath;

void hamilton(int pos, int cur){
    if (pos == n){ // buoc cuoi cung
        if (a[cur][u] == 1){ // kiem tra co duong quay ve dinh xuat phat khong
            allpath.push_back(path);
        }
        return;
    }
    for (int i = 1; i <= n; i++){
        if (a[cur][i] == 1 && !visited[i]){
            visited[i] = true;
            path[pos + 1] = i;
            hamilton(pos + 1, i);
            visited[i] = false; // tim duong di khac tai dinh hien tai
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    cin >> n >> u;
    a.assign(n + 1, vector<int>(n + 1));
    visited.assign(n + 1, false);
    path.assign(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    path[1] = u;
    visited[u] = true;
    hamilton(1, u);
    if ((int)allpath.size() == 0){
        cout << 0;
    }
    else{
        for (int i = 0; i < (int)allpath.size(); i++){
            for (int j = 1; j <= n; j++){
                cout << allpath[i][j] << " ";
            }
            cout << u << "\n";
        }
        cout << allpath.size();
    }
    return 0;
}