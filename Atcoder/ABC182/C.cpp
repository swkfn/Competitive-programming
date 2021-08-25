#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    string n;
    cin >> n;
    int k = n.size();
    int sum = 0;
    vector<int> num(10, 0);
    for (int i = 0; i < n.size(); i++) {
        sum += n[i] - '0';
        num[n[i] % 3]++;
    }
    if (sum % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }
    int rem = sum % 3;
    int ans = 0;
    if (rem == 1) {
        if (num[1] >= 1 && k > 1) {
            cout << 1 << endl;
        } else if (num[2] >= 2 && k > 2) {
            cout << 2 << endl;
        } else {
            cout << -1 << endl;
        }
    } else if (rem == 2) {
        if (num[2] >= 1 && k > 1) {
            cout << 1 << endl;
        } else if (num[1] >= 2 && k > 2) {
            cout << 2 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}