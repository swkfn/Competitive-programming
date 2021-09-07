#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> s(n), t(n), p(n);
    for (int i = 0; i < n; i++) cin >> s[i] >> t[i] >> p[i];
    vector<ll> sum(200010, 0);
    for (int i = 0; i < n; i++) {
        sum[s[i]] += p[i];
        sum[t[i]] -= p[i];
    }
    for (int i = 0; i < 200005; i++) {
        sum[i + 1] += sum[i];
        if (sum[i] > w) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}