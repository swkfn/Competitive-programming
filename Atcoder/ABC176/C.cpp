#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll sum = 0, ma = a[0];
    for (int i = 1; i < n; i++) {
        if (ma <= a[i]) {
            ma = max(ma, a[i]);
            continue;
        }
        sum += ma - a[i];
        ma = max(ma, a[i]);
    }
    cout << sum << endl;
    return 0;
}