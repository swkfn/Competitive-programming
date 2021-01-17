#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    ll q = x / d, r = x % d;
    if (q >= k) {
        cout << x - d * k << endl;
        return 0;
    }
    ll rm = k - q;
    cout << (rm % 2 ? d - r : r) << endl;
    return 0;
}