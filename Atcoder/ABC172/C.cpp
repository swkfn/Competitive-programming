#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    ll k;
    cin >> k;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    vector<ll> suma(n + 1, 0), sumb(m + 1, 0);
    for (int i = 0; i < n; i++) suma[i + 1] = suma[i] + a[i];
    for (int i = 0; i < m; i++) sumb[i + 1] = sumb[i] + b[i];
    int ma = 0, idx = m;
    for (int i = 0; i < n + 1; i++) {
        while (idx > 0 && suma[i] + sumb[idx] > k) idx--;
        if (suma[i] + sumb[idx] <= k) {
            ma = max(ma, i + idx);
        }
    }
    cout << ma << endl;
    return 0;
}