#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;
    vector<vector<int>> a(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if (x == 1 && i < j){
                a[i].push_back(j);
                a[j].push_back(i);
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << a[i].size() << " ";
        }
    }
    else{
        cout << n << endl;
        for (int i = 1; i <= n; i++){
            cout << a[i].size() << " ";
            for (int j = 0; j < (int)adj[i].size(); j++){
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}