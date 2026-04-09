#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

struct edge
{
    int x, y, w;
};

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

void bellmanford(int start, int n, vector<edge> &adj, vector<int> &parent)
{
    vector<int> d(n + 1, INF);
    d[start] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (edge e : adj)
        {
            int u = e.x, v = e.y, w = e.w;
            if (d[u] != INF && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                parent[v] = u;
            }
        }
    }
    path(start, n, d, parent);
}

void dothi(int n, vector<vector<int>> &a, vector<edge> &adj)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] != 0)
            {
                adj.push_back({i, j, a[i][j]});
            }
        }
    }
}

int main()
{
    int n, s;
    cin >> n >> s;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<edge> adj(n + 1);
    vector<int> parent(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    dothi(n, a, adj);
    bellmanford(s, n, adj, parent);

    return 0;
}