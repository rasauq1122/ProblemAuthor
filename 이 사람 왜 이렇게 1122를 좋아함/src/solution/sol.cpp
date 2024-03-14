#include <bits/stdc++.h>
using namespace std;

int q, t;
long long ub = 1e18, db = -1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> q;
    ub++, db--;
    for (int i = 1 ; i <= q ; i++) {
        long long a;
        char c;
        cin >> a >> c;
        if (c == '^') db = max(db, a);
        else ub = min(ub, a);
        if (db+1 >= ub) return cout << "Paradox!\n" << i, 0;
        if (!t && db+2 == ub) t = i;
    }

    if (db+2 == ub) cout << "I got it!\n" << t;
    else cout << "Hmm...";
}