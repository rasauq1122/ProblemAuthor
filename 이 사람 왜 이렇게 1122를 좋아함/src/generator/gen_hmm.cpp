#include <bits/stdc++.h>
using namespace std;

const string NAME = "hmm";
const int CASE = 20;

int Q = 111222;

int q, t;
long long ub = 1e18, db = -1e18;

void init() {
    t = 0;
    ub = 1e18;
    db = -1e18;
}

void solve() {
    cin >> q;
    ub++, db--;
    for (int i = 1 ; i <= q ; i++) {
        long long a;
        char c;
        cin >> a >> c;
        if (c == '^') db = max(db, a);
        else ub = min(ub, a);
        if (db+1 >= ub) return cout << "Paradox!\n" << i, (void)0;
        if (!t && db+2 == ub) t = i;
    }

    if (db+2 == ub) cout << "I got it!\n" << t;
    else cout << "Hmm...";

}

int main() {
    random_device rand;
    mt19937 seed(rand());

    uniform_int_distribution<long long> xgen(-1e18, 1e18);
    for (int case_i = 0 ; case_i < CASE ; case_i++) {
        const string caseName = NAME + to_string(case_i);
        const string inCase = caseName + ".in";
        const string outCase = caseName + ".out";

        vector<long long> w;
        
        for (int i = 0 ; i < Q ; i++) w.push_back(xgen(seed));
        
        sort(w.begin(), w.end());
        
        vector<pair<long long,bool>> v;
        uniform_int_distribution<int> qgen(0, Q);
        long long x = qgen(seed);

        for (int i = 0 ; i < Q ; i++) v.push_back({w[i], i >= x});

        shuffle(v.begin(), v.end(), seed);
        
        freopen(inCase.c_str(), "w", stdout);
        cout << Q << '\n';
        for (auto ele : v) cout << ele.first << ' ' << (ele.second ? 'v' : '^') << '\n';

        freopen(inCase.c_str(), "r", stdin);
        freopen(outCase.c_str(), "w", stdout);
        init();
        solve();
    }
}