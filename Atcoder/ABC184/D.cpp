#include <bits/stdc++.h>
using ll = long long;
using namespace std;

double dp[110][110][110];
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    for (int a = 99; a >= A; --a) {
        for (int b = 99; b >= B; --b) {
            for (int c = 99; c >= C; --c) {
                dp[a][b][c] += (double)(a) / (a + b + c) * (dp[a + 1][b][c] + 1);
                dp[a][b][c] += (double)(b) / (a + b + c) * (dp[a][b + 1][c] + 1);
                dp[a][b][c] += (double)(c) / (a + b + c) * (dp[a][b][c + 1] + 1);
            }
        }
    }
    cout << fixed << setprecision(10) << dp[A][B][C] << endl;
    return 0;
}