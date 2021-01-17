#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    vector<ll> c(n);
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
    for (int i = 0; i < n; i++) cin >> c[i];
    ll ans = -1e18;
    for (int i = 0; i < n; i++) {
        int cur = i;
        ll sum = 0;
        int h = 0;
        while (1) {
            sum += c[cur];
            h++;
            cur = p[cur];
            if (cur == i) break;
        }
        ll sum1 = 0;
        int cnt = 0;
        while (1) {
            cnt++;
            sum1 += c[cur];
            if (cnt > k) break;
            int num = (k - cnt) / h;
            ll tmp = sum1 + max(0LL, sum) * num;
            ans = max(ans, tmp);
            cur = p[cur];
            if (cur == i) break;
        }
    }
    cout << ans << endl;
    return 0;
}