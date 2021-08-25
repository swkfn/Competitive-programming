#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll x, y, a, b;

    cin >> x >> y >> a >> b;
    ll res = 0;
    ll cnt = 0;
    while (x < y) {
        ll tmp = cnt + (y - x - 1) / b;
        res = max(res, tmp);
        if (x >= (y + a -1) / a) break;
        x *= a;
        ++cnt;
    }
    cout << res << endl;
    return 0;
}