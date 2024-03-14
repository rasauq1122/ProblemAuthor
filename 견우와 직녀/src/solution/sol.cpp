#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
int sub[100001];
ll d[100001];
pair<long long,int> ans[2];

vector<vector<pair<int,int>>> edge;

int dfs1(int u, int par, ll dis) {
    sub[u] = 1;
    d[1] += dis;
    for (auto p: edge[u]) {
        auto [v, w] = p;
        if (v == par) continue;
        sub[u] += dfs1(v, u, dis+w);
    }
    return sub[u];
}

ll dfs2(int u, int par, int all) {
    ll dis = d[u];
    for (auto p: edge[u]) {
        auto [v, w] = p;
        if (v == par) continue;
        d[v] = d[u] - 1LL*sub[v]*w + 1LL*(all-sub[v])*w;
        dis += dfs2(v, u, all);
    }
    return dis;
}

int main() {
    for (int idx = 0 ; idx < 2 ; idx++) {
        m = n;
        cin >> n;
        memset(d, 0, sizeof(d));
        memset(sub, 0, sizeof(sub));
        edge = vector<vector<pair<int,int>>>(n+1);

        for (int i = 1 ; i < n ; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            edge[a].push_back({b, c});
            edge[b].push_back({a, c});
        }

        dfs1(1, -1, 0);
        dfs2(1, -1, n);
        
        pair<long long,int> nin = {INT64_MAX, 0};
        for (int i = 1 ; i <= n ; i++) nin = min(nin, make_pair(d[i], i));
        ans[idx] = nin;
    }

    cout << ans[0].second << ' ' << ans[1].second << '\n';
    cout << n*ans[0].first + m*ans[1].first + n*m << '\n';
}