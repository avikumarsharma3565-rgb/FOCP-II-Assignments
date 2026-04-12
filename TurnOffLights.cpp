#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (int l = 1; l <= n; l++) {
        int count = 0;
        int i = 0;

        while (i < n) {
            if (s[i] == '1') {
                count++;
                i += l;
            } else {
                i++;
            }
        }

        if (count <= k) {
            cout << l;
            return 0;
        }
    }

    return 0;
}
