#include <bits/stdc++.h>
using namespace std;
class Bank {
    unordered_map<int, int> acc;
public:
    int CREATE(int x, int y) {
        if (acc.count(x)) {
            acc[x] += y;
            return 0;
        }
        acc[x] = y;
        return 1;
    }
    int DEBIT(int x, int y) {
        if (!acc.count(x) || acc[x] < y)
            return 0;
        acc[x] -= y;
        return 1;
    }
    int CREDIT(int x, int y) {
        if (!acc.count(x))
            return 0;
        acc[x] += y;
        return 1;
    }
    int BALANCE(int x) {
        if (!acc.count(x))
            return -1;
        return acc[x];
    }
};
int main() {
    int Q;
    cin >> Q;
    cin.ignore();
    Bank b;
    for (int i = 0; i < Q; i++) {
        string query;
        getline(cin, query);
        stringstream ss(query);
        string op;
        ss >> op;
        if (op == "CREATE") {
            int x, y;
            ss >> x >> y;
            cout << b.CREATE(x, y) << endl;
        }
        else if (op == "DEBIT") {
            int x, y;
            ss >> x >> y;
            cout << b.DEBIT(x, y) << endl;
        }
        else if (op == "CREDIT") {
            int x, y;
            ss >> x >> y;
            cout << b.CREDIT(x, y) << endl;
        }
        else if (op == "BALANCE") {
            int x;
            ss >> x;
            cout << b.BALANCE(x) << endl;
        }
    }
    return 0;
}
