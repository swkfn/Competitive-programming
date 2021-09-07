#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;

ll mod = 998244353;
int main() {
    int n, k;
    cin >> n >> k;
    vector<p> s;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        s.push_back(p(l, r));
    }
    vector<ll> dp(n + 1, 0), sdp(n + 1, 0);
    dp[0] = 1, sdp[1] = 1;
    for (int i = 1; i < n; i++) {
        for (auto v : s) {
            int left = max(0, i - v.second);
            int right = max(0, i - v.first + 1);
            dp[i] += (sdp[right] - sdp[left] + mod) % mod;
        }
        sdp[i + 1] = (sdp[i] + dp[i] + mod) % mod;
    }
    cout << (dp[n - 1] + mod) % mod << endl;
    return 0;
}