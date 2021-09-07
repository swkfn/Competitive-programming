#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dist(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
            dist[j][i] = dist[i][j];
        }
    }
    vector<int> v(n - 1, 0);
    for (int i = 0; i < n - 1; i++) v[i] = i + 1;
    int ans = 0;
    do {
        ll sum = 0;
        int cur = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += dist[cur][v[i]];
            cur = v[i];
        }
        sum += dist[cur][0];
        if (sum == k) ans++;
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}