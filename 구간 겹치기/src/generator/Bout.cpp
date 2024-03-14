#include <bits/stdc++.h>
#define INF (int)1e9+2
using namespace std;

int main() {
    string k;
    cin >> k;
    
    freopen((k+".out").c_str(), "w", stdout);
    freopen((k+".in").c_str(), "r", stdin);

    int n, q;
    cin >> n >> q;

    vector < pair <int, int> > v;
    vector < int > cord;
    
    for (int i = 0, s, e ; i < n ; i++) {
        cin >> s >> e;
        v.push_back({s,e});
        cord.push_back(s);
        cord.push_back(e);
    }

    sort(cord.begin(), cord.end());
    cord.erase(unique(cord.begin(), cord.end()), cord.end());
    
    map <int, int> m;

    for (int i = 0 ; i < cord.size() ; i++) {
        m[cord[i]] = i;
    }

    int len = cord.size();
    vector < vector <int> > dist(len, vector<int>(len, INF));

    for (int i = 0 ; i < n ; i++) {
        int s = m[v[i].first], e = m[v[i].second];
        for (int j = s ; j <= e ; j++) {
            for (int k = s ; k <= e ; k++) {
                dist[j][k] = min(dist[j][k], v[i].second-v[i].first+1);
            }
        }
    }

    for (int k = 0 ; k < len ; k++) {
        for (int i = 0 ; i < len ; i++) {
            for (int j = 0 ; j < len ; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    for (int i = 0, a, b ; i < q ; i++) {
        cin >> a >> b;
        int s = upper_bound(cord.begin(), cord.end(), a) - cord.begin() - 1;
        int e = lower_bound(cord.begin(), cord.end(), b) - cord.begin();
        if (a < cord.front() || cord.back() < b || dist[s][e] == INF) {
            cout << -1 << '\n';
        }
        else {
            cout << dist[s][e] << '\n';
        }
    }
}