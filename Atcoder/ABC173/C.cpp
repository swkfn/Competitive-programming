#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    string grid[h];
    for (int i = 0; i < h; i++) cin >> grid[i];
    string tmp[h];
    int ans = 0;
    for (int b1 = 0; b1 < 1 << h; b1++) {
        for (int b2 = 0; b2 < 1 << w; b2++) {
            for (int i = 0; i < h; i++) tmp[i] = grid[i];
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (b1 >> i & 1) {
                        tmp[i][j] = 'r';
                    }
                    if (b2 >> j & 1) {
                        tmp[i][j] = 'r';
                    }
                }
            }
            int cnt = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (tmp[i][j] == '#') cnt++;
                }
            }
            if (cnt == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}