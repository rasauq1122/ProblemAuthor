#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 111222LL*111222LL;

vector<vector<int>> edge;
vector<vector<int>> dedge;

int n, b, d;
int dp[33][111223];

void dfs(int i, int p) {
    for (auto nxt : edge[i]) {
        if (nxt == p) continue;
        dfs(nxt, i);
        dedge[i].push_back(nxt);
    }
}

int foo(int h, int idx) {
    int &ret = dp[h][idx];

    if (ret != -1) return ret;

    if (!h) {
        ret = 0;
        for (auto nxt: dedge[idx]) {
            ret += foo(0, nxt) + d;
        }

        return ret;
    }

    if (!dedge[idx].size()) return ret = b*((1LL<<h+1)-2);
    if (dedge[idx].size() == 1) return ret = b*((1LL<<h)-1) + foo(h-1, dedge[idx][0]);

    int nin1 = MAX, nin2 = MAX;
    auto update = [&](int val) {
        if (val < nin1) nin2 = nin1, nin1 = val;
        else if (val < nin2) nin2 = val;
    };

    int sum = 0;
    for (auto nxt: dedge[idx]) {
        sum += foo(0, nxt) + d;
        update(foo(h-1, nxt) - foo(0, nxt) - d);
    }

    return ret = sum + nin1 + nin2;
}

signed main() {
    cin >> n >> b >> d;
    
    edge = vector<vector<int>>(n+1);
    dedge = vector<vector<int>>(n+1);
    
    for (int i = 1 ; i < n ; i++) {
        int u, v;
        cin >> u >> v;

        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    int nin = MAX;
    memset(dp, -1, sizeof(dp));
    
    dfs(1, 0);
    for (int i = 0 ; i < 33 ; i++) {
        nin = min(nin, foo(i, 1));
    }

    cout << nin << endl;
}