#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int a[1000001];
int main() {
    int k;
    cin >> k;
    a[1] = 7 % k;
    for (int i = 2; i <= k; i++) a[i] = (a[i - 1] * 10 + 7) % k;
    for (int i = 1; i <= k; i++) {
        if (a[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}