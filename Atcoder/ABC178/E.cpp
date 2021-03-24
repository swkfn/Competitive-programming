#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> x(n, 0), y(n, 0);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    vector<ll> z(n, 0), w(n, 0);
    for (int i = 0; i < n; i++) {
        z[i] = x[i] + y[i];
        w[i] = x[i] - y[i];
    }
    sort(z.begin(), z.end());
    sort(w.begin(), w.end());
    cout << max(z[n - 1] - z[0], w[n - 1] - w[0]) << endl;
    return 0;
}