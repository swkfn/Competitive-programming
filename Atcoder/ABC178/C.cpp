#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll mod = 1000000007;
ll powmod(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    ll all = powmod(10, n);
    ll sub = (powmod(9, n) + powmod(9, n)) % mod;
    ll add = powmod(8, n);
    ll ans = all - sub + add + mod;
    cout << ans % mod << endl;
    return 0;
}