#include <bits/stdc++.h>
#define int long long
#define INF (int)1e18
#include <random>
using namespace std;

signed main() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> arr(-1e+9, 1e+9);
 
    for (int k = 1 ; k <= 20 ; k++) 
    {   
        freopen(("smr"+to_string(k)+".in").c_str(), "w", stdout);

        cout << 1 << ' ' << 1 << '\n';
        for (int i = 0 ; i < 1 ; i++) {
            int s = arr(gen), e = arr(gen);
            while (s == e) {
                s = arr(gen); 
                e = arr(gen);
            }
            cout << min(s,e) << ' ' << max(s,e) << '\n';
        }

        for (int i = 0 ; i < 1 ; i++) {
            int a = arr(gen), b = arr(gen);
            while (a == b) {
                a = arr(gen); 
                b = arr(gen);
            }
            cout << min(a,b) << ' ' << max(a,b) << '\n';
        }
    }

    for (int k = 1 ; k <= 20 ; k++) {

        freopen(("smr"+to_string(k)+".out").c_str(), "w", stdout);
        freopen(("smr"+to_string(k)+".in").c_str(), "r", stdin);

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
}