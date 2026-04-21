#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;
    vector<vector<int>> a(n + 1);
    vector<pair<int, int>> edge;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x == 1 && i < j)
            {
                a[i].push_back(j);
                a[j].push_back(i);
                edge.push_back({i, j});
            }
        }
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i].size() << " ";
        }
    }
    else
    {
        int m = edge.size();
        cout << n << " " << m << endl;
        vector<vector<int>> mtlt(n + 1, vector<int>(m + 1, 0));
        // chuyen tu danh sach canh sang ma tran lien thuoc
        for (int i = 1; i <= m; i++)
        {
            mtlt[edge[i - 1].first][i] = 1;
            mtlt[edge[i - 1].second][i] = 1;
        }
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