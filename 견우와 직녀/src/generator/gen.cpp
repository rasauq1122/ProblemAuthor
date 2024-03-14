#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;


vector<pair<int, int>> new_edge(int n) {
    vector<pair<int, int>> edge;
    vector<int> p(n);
    
    for (int i = 0 ; i < n ; i++) {
        if (i) p[i] = rnd.next(i);
    }
    
    vector<int> perm(n);
    for (int i = 0 ; i < n ; i++) perm[i] = i;
    shuffle(perm.begin()+1, perm.end());
    
    for (int i = 1 ; i < n ; i++) {
        if (rnd.next(2)) edge.push_back({perm[i], perm[p[i]]});
        else edge.push_back({perm[p[i]], perm[i]});
    }
    
    shuffle(edge.begin(), edge.end());
    return edge;
}

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    int n = rnd.next(1, 100'000);
    cout << n << '\n';
    auto n_edge = new_edge(n);
    for (int i = 0 ; i < n-1 ; i++) {
        int c = rnd.next(1, 10'000);
        cout << n_edge[i].first + 1 << ' ' << n_edge[i].second + 1 << ' ' << c << '\n';
    }
    
    int m = rnd.next(1, 100'000);
    cout << m << '\n';
    auto m_edge = new_edge(m);
    for (int i = 0 ; i < m-1 ; i++) {
        int c = rnd.next(1, 10'000);
        cout << m_edge[i].first + 1 << ' ' << m_edge[i].second + 1 << ' ' << c << '\n';
    }
}