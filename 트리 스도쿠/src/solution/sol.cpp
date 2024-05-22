#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<pair<int,int>> v; 
vector<int> ans;
vector<vector<int>> edges;

signed main() {
    int n;
    cin >> n;
    
    ans = vector<int>(n);
    edges = vector<vector<int>>(n);
    for (int i = 1 ; i <= n ; i++) {
        int x;
        cin >> x;
        v.push_back(make_pair(x, i));
    }

    for (int i = 1 ; i < n ; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    sort(v.begin(), v.end());
    queue<int> q;
    
    q.push(0);
    ans[0] = v[0].second;
    for (int i = 1 ; !q.empty() ;) {
        int u = q.front();
        q.pop();
        for (auto vtx : edges[u]) {
            if (!ans[vtx]) {
                ans[vtx] = v[i++].second; 
                q.push(vtx);
            }
        }
    }

    cout << "YES\n";
    for (int i = 0 ; i < n ; i++) cout << ans[i] << " \n"[i+1==n];
}