#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector<int> preprocess(int n) {
    vector<int> res(n, -1);
    vector<bool> isprime(n, true);
    isprime[0] = isprime[1] = false;
    res[0] = 0;
    res[1] = 1;
    for (int i = 2; i < n; i++) {
        if (isprime[i]) {
            res[i] = i;
            for (int j = 2 * i; j < n; j += i) {
                isprime[j] = false;
                if (res[j] == -1) res[j] = i;
            }
        }
    }
    return res;
}

const int MAX = 1100000;
int main() {
    int n;
    cin >> n;
    vector<int> a(n), num(MAX, 0);;
    int ma = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
        num[a[i]]++;
    }
    auto v = preprocess(ma);
    bool flag = true;
    for (int i = 2; i < MAX; i++) {
        if (i >= v.size() || !v[i]) continue;
        int sum = 0;
        for (int j = i; j < MAX; j += i) {
            sum += num[j];
        }
        if (sum > 1) flag = false;
    }
    if (flag) {
        cout << "pairwise coprime" << endl;
        return 0;
    }
    int g = a[0];
    for (int i = 1; i < n; i++) g = gcd(g, a[i]);
    if (g == 1)
        cout << "setwise coprime" << endl;
    else
        cout << "not coprime" << endl;
    return 0;
}