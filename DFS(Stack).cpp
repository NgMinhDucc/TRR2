#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool> &visited, vector<vector<int>> &adj){
    stack<int> st;
    st.push(u);
    visited[u] = true;
    cout << u << " ";
    while (!st.empty()){
        int s = st.top();
        st.pop();
        for (int v : adj[s]){
            if (!visited[v]){
                cout << v << " ";
                visited[v] = true;
                st.push(s);
                st.push(v);
                break;
            }
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
    int n, u;
    cin >> n >> u;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    dothi(n, a, adj);
    dfs(u, visited, adj);
    return 0;
}