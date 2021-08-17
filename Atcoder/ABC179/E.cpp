#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<int> used(m, -1);
    vector<ll> his, s;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (used[x] != -1) {
            int p = used[x];
            for (ll j = p; j < i; j++) {
                s.push_back(his[j]);
            }
            break;
        }
        used[x] = i;
        his.push_back(x);
        res += x;
        x = (x * x) % m;
    }
    n -= his.size();

    if (n == 0) {
        cout << res << endl;
        return 0;
    }
    vector<ll> sum(s.size() + 1, 0);
    for (int i = 0; i < s.size(); ++i) sum[i + 1] = sum[i] + s[i];

    ll q = n / s.size();
    ll r = n % s.size();
    res += sum[s.size()] * q + sum[r];
    cout << res << endl;
    return 0;
}