#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0, tplt = 0;
vector<vector<int>> a;
vector<bool> visited;
vector<int> low, num;
stack<int> st;

void tarjan(int u){
    cnt += 1;
    low[u] = num[u] = cnt;
    st.push(u);
    visited[u] = true;
    for (int v = 1; v <= n; v++){
        if (a[u][v]){
            if (!num[v]){
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
            else if (visited[v]){
                low[u] = min(low[u], num[v]);
            }
        }
    }
    if (low[u] == num[u]){
        tplt += 1;
        int v;
        do{
            v = st.top();
            st.pop();
            cout << v << " ";
            visited[v] = false;
        } while (v != u);
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a.assign(n + 1, vector<int>(n + 1));
    visited.assign(n + 1, false);
    low.assign(n + 1, 0);
    num.assign(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        if (num[i] == 0){
            tarjan(i);
        }
    }
    if (tplt == 1) cout << "manh";
    else cout << "yeu";
    return 0;
}