#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        // frequency count
        map<int,int> freq;
        for(int x : a) freq[x]++;

        // descending order
        vector<int> vals;
        for(auto it : freq) vals.push_back(it.first);
        sort(vals.rbegin(), vals.rend());

        long long alex = 0, bob = 0;
        int turn = 0;

        for(int val : vals) {
            int f = freq[val];

            // first pick
            if(turn == 0) alex += val;
            else bob += val;
            turn ^= 1;

            // second pick (if freq >= 2)
            if(f >= 2) {
                if(turn == 0) alex += val;
                else bob += val;
                turn ^= 1;
            }
        }

        if(alex > bob)
            cout << "Alex\n";
        else
            cout << "Bob\n";
    }

    return 0;
}
