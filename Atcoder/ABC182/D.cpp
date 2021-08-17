#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), s(n + 1, 0), m(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
        m[i + 1] = max(m[i], s[i + 1]);
    }
    ll res = 0LL, cur = 0LL;
    for (int i = 0; i < n; i++) {
        res = max(res, cur + m[i + 1]);
        cur += s[i + 1];
    }
    cout << res << endl;
    return 0;
}