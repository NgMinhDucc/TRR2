#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m;
    cin >> t >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            int deg = 0;
            for (int j : a[i])
            {
                if (j == 1)
                {
                    deg += 1;
                }
            }
            cout << deg << " ";
        }
    }
    else
    {
        cout << n << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}