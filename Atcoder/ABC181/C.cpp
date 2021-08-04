#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || i == k || j == k) continue;
                int dx1 = x[i] - x[j];
                int dy1 = y[i] - y[j];
                int dx2 = x[j] - x[k];
                int dy2 = y[j] - y[k];
                if (dx2 * dy1 == dx1 * dy2) ans++;
            }
        }
    }
    cout << (ans == 0 ? "No" : "Yes") << endl;
    return 0;
}