#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    ll a = x, sum = a;
    for (int i = 1; i < n; i++) {
        a = (a * a) % m;
        sum += a;
    }
    cout << sum << endl;
    return 0;
}