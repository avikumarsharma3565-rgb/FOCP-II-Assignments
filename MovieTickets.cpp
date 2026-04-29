#include <bits/stdc++.h>
using namespace std;
class MovieTicket {
    unordered_map<int, unordered_set<int>> booked; 
    unordered_map<int, int> seats;                 
public:
    bool BOOK(int x, int y) {
        if (booked[y].count(x) || seats[y] >= 100)
            return false;
        booked[y].insert(x);
        seats[y]++;
        return true;
    }
    bool CANCEL(int x, int y) {
        if (!booked[y].count(x))
            return false;
        booked[y].erase(x);
        seats[y]--;
        return true;
    }
    bool IS_BOOKED(int x, int y) {
        return booked[y].count(x);
    }
    int AVAILABLE_TICKETS(int y) {
        return 100 - seats[y];
    }
};
int main() {
    int Q;
    cin >> Q;
    cin.ignore();
    MovieTicket mt;
    while (Q--) {
        string query;
        getline(cin, query);
        stringstream ss(query);
        string op;
        ss >> op;
        if (op == "BOOK") {
            int x, y;
            ss >> x >> y;
            cout << (mt.BOOK(x, y) ? "true" : "false") << endl;
        }
        else if (op == "CANCEL") {
            int x, y;
            ss >> x >> y;
            cout << (mt.CANCEL(x, y) ? "true" : "false") << endl;
        }
        else if (op == "IS_BOOKED") {
            int x, y;
            ss >> x >> y;
            cout << (mt.IS_BOOKED(x, y) ? "true" : "false") << endl;
        }
        else if (op == "AVAILABLE_TICKETS") {
            int y;
            ss >> y;
            cout << mt.AVAILABLE_TICKETS(y) << endl;
        }
    }
    return 0;
}


