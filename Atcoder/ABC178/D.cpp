#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll mod = 1000000007;
int main() {
    int s;
    cin >> s;
    vector<ll> dp(s + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= s; i++) {
        for (int j = 0; j <= i - 3; j++) {
            dp[i] = (dp[i] + dp[j]) % mod;
        }
    }
    cout << dp[s] % mod << endl;
    return 0;
}