#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = 0, w = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') r++;
    }
    int ans = 0;
    for (int i = 0; i < r; i++) {
        if (s[i] == 'W') ans++;
    }
    cout << ans << endl;
    return 0;
}