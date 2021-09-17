#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int l, q;
    cin >> l >> q;
    set<int> s;
    s.insert(l);
    for (int i = 0; i < q; i++) {
        int c, x;
        cin >> c >> x;
        if (c == 1) {
            s.insert(x);
        } else if (c == 2) {
            auto itr = s.lower_bound(x);
            if (itr == s.begin()) {
                cout << *itr << endl;
            } else {
                cout << *itr - *(--itr) << endl;
            }
        }
    }
    return 0;
}