#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int q;
    cin >> q;
    priority_queue<int> que2;
    queue<int> que1;
    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 1) {
            int x;
            cin >> x;
            que1.push(x);
        } else if (c == 2) {
            if (que2.empty()) {
                cout << que1.front() << endl;
                que1.pop();
            } else {
                cout << -que2.top() << endl;
                que2.pop();
            }
        } else if (c == 3) {
            while (!que1.empty()) {
                que2.push(-que1.front());
                que1.pop();
            }
        }
    }
    return 0;
}