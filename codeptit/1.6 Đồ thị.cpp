#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m;
    cin >> t >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> mtlt(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
        mtlt[u][i] = 1;
        mtlt[v][i] = 1;
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            int deg = 0;
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 1)
                {
                    deg += 1;
                }
            }
            cout << deg << " ";
        }
    }
    else
    {
        cout << n << " " << m << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << mtlt[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}