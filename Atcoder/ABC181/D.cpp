#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << (s == "8" ? "Yes" : "No") << endl;
        return 0;
    }
    if (s.size() == 2) {
        int n1 = (s[0] - '0') * 10 + s[1] - '0';
        int n2 = (s[1] - '0') * 10 + s[0] - '0';
        cout << (n1 % 8 == 0 || n2 % 8 == 0 ? "Yes" : "No") << endl;
        return 0;
    }
    vector<int> num(10, 0);
    for (int i = 0; i < s.size(); i++) num[s[i] - '0']++;
    for (int i = 104; i < 1000; i += 8) {
        int flag = 1;
        vector<int> num1 = num;
        for (char x : to_string(i)) num1[x - '0']--;
        for (int j = 0; j < 10; j++) {
            if (num1[j] < 0) flag = 0;
        }
        if (flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}