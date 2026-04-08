#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
};

void Make(int n, vector<int> &parent, vector<int> &sz){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int v, vector<int> &parent){
    if (v == parent[v]){ // tim root
        return v;
    }
    return parent[v] = Find(parent[v], parent); // tim sau hon
}

bool Union(int a, int b, vector<int> &parent, vector<int> &sz){
    int x = Find(a, parent);
    int y = Find(b, parent);
    if (x == y){
        return false; // bo vi canh tao thanh chu trinh
    }
    if (sz[x] < sz[y]){
        swap(x, y);
    }
    parent[y] = x;
    sz[x] += sz[y];
    return true;
}

bool cmp(edge &a, edge &b){
    return a.w < b.w;
}

void kruskal(int n, vector<edge> &canh, vector<int> &parent, vector<int> &sz){
    vector<edge> mst;
    int d = 0;

    stable_sort(canh.begin(), canh.end(), cmp);

    for (int i = 0; i < (int)canh.size(); i++){
        if ((int)mst.size() == n - 1){
            break;
        }
        edge e = canh[i];
        if (Union(e.u, e.v, parent, sz)){
            mst.push_back(e);
            d += e.w;
        }
    }
    if ((int)mst.size() != n - 1){
        cout << "Do thi khong lien thong";
    }
    else{
        cout << "dH = " << d << endl;
        for (auto it : mst){
            if (it.u > it.v) cout << it.v << " " << it.u << endl;
            else cout << it.u << " " << it.v << endl;
        }
    }
}

void dothi(int n, vector<vector<int>> &a, vector<edge> &canh){
    edge e;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] != 0 && i < j){
                e.u = i, e.v = j, e.w = a[i][j];
                canh.push_back(e);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    vector<int> parent(n + 1);
    vector<int> sz(n + 1);
    vector<edge> canh;

    dothi(n, a, canh);
    Make(n, parent, sz);
    kruskal(n, canh, parent, sz);
    return 0;
}