#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> spf(MAXN + 1);
    
    // smallest prime factor (SPF) precompute
    for(int i = 1; i <= MAXN; i++) spf[i] = i;

    for(int i = 2; i * i <= MAXN; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j <= MAXN; j += i) {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int count = 0;

        // count distinct prime factors
        while(n > 1) {
            int p = spf[n];
            count++;
            while(n % p == 0) {
                n /= p;
            }
        }

        cout << (1 << count) << '\n';
    }

    return 0;
}

