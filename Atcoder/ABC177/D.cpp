#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct UnionFind {
    vector<int> par;
    int cnt;
    UnionFind(int n) : par(n, -1), cnt(n) {}
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (par[y] < par[x]) swap(x, y);
            par[x] += par[y];
            par[y] = x;
            cnt--;
        }
    }
    int find(int x) { return par[x] < 0 ? x : par[x] = find(par[x]); }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -par[find(x)]; }
    int size() { return cnt; }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        uf.unite(a[i], b[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, uf.size(i));
    }
    cout << ans << endl;
    return 0;
}