#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll sum = a[0];
    int idx = 1;
    for (int i = 2; i < n; i++) {
        sum += a[idx];
        if (i % 2 == 1) idx++;
    }
    cout << sum << endl;
    return 0;
}