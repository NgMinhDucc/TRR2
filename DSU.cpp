#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;
vector<int> parent;
vector<int> sz;

void make(){ // khoi tao cac tap hop
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v){
    if (v == parent[v]){
        return v; // tra ve dinh cha cua v
    }
    return parent[v] = find(parent[v]); // tiep tuc tim kiem len tren
}

void unionn(int a, int b){
    a = find(a);
    b = find(b);
    if (a != b){
        if (sz[a] < sz[b]){
            parent[a] = b;
            sz[b] += sz[a];
        }
        else{
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
}

int main(){
    cin >> n;
    a.assign(n + 1, vector<int>(n + 1));
    parent.assign(n + 1, 0);
    sz.assign(n + 1, 0);

    make();
    return 0;
}