#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n), z(n);
    vector<vector<ll> > dp(1 << n, vector<ll>(n, 1e16));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
    for (int bit = 0; bit < (1 << n); bit++) {
        for (int v = 0; v < n; v++) {
            for (int u = 0; u < n; u++) {
                if (bit != 0 && !(bit >> u & 1)) continue;
                if (u != v && !(bit >> v & 1)) {
                    ll cost = abs(x[u] - x[v]) + abs(y[u] - y[v]) +
                              max(0LL, z[u] - z[v]);
                    dp[bit | 1 << v][v] =
                        min(dp[bit | 1 << v][v], dp[bit][u] + cost);
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][0] << endl;
    return 0;
}