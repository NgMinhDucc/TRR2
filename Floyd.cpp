#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void path(int n, vector<vector<int>> &d, vector<vector<int>> &nx)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == INF)
            {
                cout << "K/c " << i << " -> " << j << " = INF;\n";
                continue;
            }
            cout << "K/c " << i << " -> " << j << " = " << d[i][j] << ";   ";
            if (i == j)
            {
                cout << i;
            }
            else
            {
                int cur = i;
                cout << cur;
                while (cur != j)
                {
                    cur = nx[cur][j];
                    cout << " -> " << cur;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

void floyd(int n, vector<vector<int>> &a, vector<vector<int>> &d, vector<vector<int>> &nx)
{
    // khoi tao
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                d[i][j] = 0; // kc tu 1 dinh toi chinh no luon = 0
                nx[i][j] = i;
            }
            else if (a[i][j] != 0)
            {
                d[i][j] = a[i][j];
                nx[i][j] = j;
            }
            else
            {
                d[i][j] = INF;
                nx[i][j] = -1;
            }
        }
    }

    // lap
    for (int k = 1; k <= n; k++) // dinh trung gian
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] < INF && d[k][j] < INF)
                {
                    if (d[i][j] > d[i][k] + d[k][j])
                    {
                        d[i][j] = d[i][k] + d[k][j];
                        nx[i][j] = nx[i][k];
                    }
                }
            }
        }
    }

    // tra ket qua
    path(n, d, nx);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> d(n + 1, vector<int>(n + 1));
    vector<vector<int>> nx(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    floyd(n, a, d, nx);

    return 0;
}