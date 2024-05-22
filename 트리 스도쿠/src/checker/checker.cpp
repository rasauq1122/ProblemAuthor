#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
vector<int> d;
vector<int> assign;
vector<vector<int>> edges; 
vector<int> cost;

void dfs(int u, int p) {
    for (auto v : edges[u]) {
        if (v == p) continue;
        cost.push_back(d[assign[u-1]-1] + d[assign[v-1]-1]);
        dfs(v, u);
    }
}
 
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    
    int n = inf.readInt();
    d = inf.readInts(n, -1'000'000'000, 1'000'000'000);
    edges = vector<vector<int>>(n+1);
    for (int i = 1 ; i < n ; i++) {
        int u = inf.readInt(), v = inf.readInt();
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    string s = ouf.readToken("YES|NO");
    if (s == "NO") quitf(_wa, "possible case");
    
    assign = ouf.readInts(n, 1, n);
    vector <bool> perm_test(n+1);
    for (int i = 0 ; i < n ; i++) {
        if (perm_test[assign[i]]) quitf(_wa, "not permutation");
        perm_test[assign[i]] = true;
    }
    
    dfs(1, 0);
    sort(cost.begin(), cost.end());
    for (int i = 1 ; i < n-1 ; i++) {
       if (cost[i-1] == cost[i]) quitf(_wa, "not duplicate cost");
    }
    
    quitf(_ok, "ok");
}
