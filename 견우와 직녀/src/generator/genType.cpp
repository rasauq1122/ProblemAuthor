#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> make_tree(int n) {
    vector<pair<int, int>> rtn;
    vector<int> p(n);

    for (int i = 0 ; i < n ; i++) p[i] = i+1;
    shuffle(p.begin(), p.end());

    for (int i = 1 ; i < n ; i++) {
        int j = rnd.next(i);
        if (rnd.next(2)) rtn.push_back({p[i], p[j]});
        else rtn.push_back({p[j], p[i]});
    }

    return rtn;
}

vector<pair<int, int>> make_line(int n) {
    vector<pair<int, int>> rtn;
    vector<int> p(n);

    for (int i = 0 ; i < n ; i++) p[i] = i+1;
    shuffle(p.begin(), p.end());
    for (int i = 1 ; i < n ; i++) {
        if (rnd.next(2)) rtn.push_back({p[i-1], p[i]});
        else rtn.push_back({p[i], p[i-1]});
    }
    
    shuffle(rtn.begin(), rtn.end());
    return rtn;
}

vector<pair<int, int>> make_pbt(int n) {
    int cnt = 0, h = 0;
    vector<pair<int, int>> rtn;
    vector<int> p(n);

    queue <int> q;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int i = 0 ; i < 2 ; i++) {
            int v = ++cnt;
            if (v < n) {
                if (rnd.next(2)) rtn.push_back({u, v});
                else rtn.push_back({v, u});
                q.push(v);
            }
        }
    }

    for (int i = 0 ; i < n ; i++) p[i] = i+1;
    shuffle(p.begin(), p.end());

    for (int i = 0 ; i < n-1 ; i++) {
        int u = p[rtn[i].first], v = p[rtn[i].second];
        if (rnd.next(2)) rtn[i] = {u, v};
        else rtn[i] = {v, u};
    }

    shuffle(rtn.begin(), rtn.end());
    return rtn;
}

vector<pair<int, int>> make_star(int n) {
    vector<pair<int, int>> rtn;
    vector<int> p(n);

    for (int i = 0 ; i < n ; i++) p[i] = i+1;
    shuffle(p.begin(), p.end());
    for (int i = 1 ; i < n ; i++) {
        if (rnd.next(2)) rtn.push_back({p[0], p[i]});
        else rtn.push_back({p[i], p[0]});
    }
    
    shuffle(rtn.begin(), rtn.end());
    return rtn;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n[2];
    n[0] = opt<int>("n");
    n[1] = opt<int>("m");
    
    int type[2];
    type[0] = opt<int>("e_type");
    type[1] = opt<int>("w_type");
    
    bool full = opt<bool>("full");
    
    vector<pair<int,int>> edge[2];
    
    for (int i = 0 ; i < 2 ; i++) {
        if (type[i] == 0) edge[i] = make_tree(n[i]);
        else if (type[i] == 1) edge[i] = make_line(n[i]);
        else if (type[i] == 2) edge[i] = make_star(n[i]);
        else edge[i] = make_pbt(n[i]);
    }
    
    for (int i = 0 ; i < 2 ; i++) {
        cout << n[i] << '\n';
        for (auto [u, v] : edge[i]) {
            cout << u << ' ' << v << ' ' << (full ? 10'000 : rnd.next(1, 10'000)) << '\n';
        }
    }
}