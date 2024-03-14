#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0, x ; i < n ; i++) {
        cin >> x;
        v.push_back({x,i+1});
    }
    sort(v.begin(), v.end());
    for (int i = 0 ; i < min(3, n-1) ; i++) if (v[n-1-i].first - v[n-2-i].first > m) return cout << "NO", 0;
    cout << "YES\n";
    for (int i = 0 ; i < min(2, n) ; i++) cout << v[n-1-i].second << ' ';
    for (int i = 0 ; i < n-2 ; i++) cout << v[i].second << ' ';
}