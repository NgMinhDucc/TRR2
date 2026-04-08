#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void path(int start, int n, vector<int> &d, vector<int> &parent)
{
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == INF)
        {
            cout << "K/c " << start << " -> " << i << " = " << "INF" << ";\n";
            continue;
        }

        cout << "K/c " << start << " -> " << i << " = " << d[i] << ";        ";

        if (i == start)
        {
            cout << start << " <- " << start;
        }
        else
        {
            int cur = i;
            cout << cur;
            while (cur != start)
            {
                cur = parent[cur];
                cout << " <- " << cur;
            }
        }
        cout << endl;
    }
}

void dijkstra(int start, int n, vector<vector<pair<int, int>>> &adj, vector<int> &parent)
{
    vector<int> d(n + 1, INF);
    d[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // kc tu dinh start toi chinh no = 0

    while (!pq.empty())
    {
        pair<int, int> top = pq.top(); // chon dinh co kc ngan nhat tu start
        pq.pop();
        int kc = top.first;
        int u = top.second;
        if (kc > d[u])
        {
            continue; // kc hien tai da la ngan nhat
        }
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w; // cap nhat kc ngan hon
                pq.push({d[v], v});
                parent[v] = u;
            }
        }
    }
    path(start, n, d, parent);
}

void dothi(int n, vector<vector<int>> &a, vector<vector<pair<int ,int>>> &adj)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] != 0)
            {
                adj[i].push_back({j, a[i][j]});
            }
        }
    }
}

int main()
{
    int n, s;
    cin >> n >> s;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> parent(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    dothi(n, a, adj);
    dijkstra(s, n, adj, parent);

    return 0;
}