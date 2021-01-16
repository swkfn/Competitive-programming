#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll t = n / i;
        ans += t * (t + 1) / 2 * i;
    }
    cout << ans << endl;
    return 0;
}